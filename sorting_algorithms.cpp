class PriorityQueue{
private:
  std::vector<int> heap;
  
  int parent(int i){
    return i/2;
  }
  int leftChild(int i){
    return 2*i;
  }
  int rightChild(int i){
    return 2*i+1;
  }
  
  void heapUp(int i) {
    while (i>1 && heap[parent(i)]>heap[i]){
      std::swap(heap[parent(i)], heap[i]);
      i=parent(i);
    }
  }
  
  void heapDown(int i) {
    int maxIndex=i;
    int l=leftChild(i);
    int r=rightChild(i);
    
    if(l<(int)heap.size() && heap[maxIndex]>heap[l]){
      maxIndex=l;
    }
    if(r<(int)heap.size() && heap[maxIndex]>heap[r]){
      maxIndex=r;
    }
    if(i != maxIndex){
      std::swap(heap[i],heap[maxIndex]);
      heapDown(maxIndex);
    }
  }
  
public:
  PriorityQueue(){
    heap.push_back(0);
  }
  
  void insert(int var){
    heap.push_back(var);
    heapUp(heap.size()-1);
  }
  
  int getMin() const{
    return heap[1];
  }
  
  int extractMin(){
    int min=heap[1];
    heap[1]=heap.back();
    heap.pop_back();
    if(heap.size()>1){
      heapDown(1);
    }
    return min;
  }
  
  bool isEmpty() const{
    return heap.size() == 1;
  }
};

void insertionSort(std::vector<int>& data) {
  for(int i = 1; i < data.size(); ++i) {
    int key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
    }
}

void heapSort(std::vector<int>& data){
  PriorityQueue pq;
  for(int i=0;i<data.size();i++){
    pq.insert(data[i]);
  }
  for(int i=0;i<data.size();i++){
    data[i] = pq.extractMin();
  }
}

int partition(std::vector<int>& data, int low, int high) {
  int pivot_index = low+std::rand()%(high-low+1);
  std::swap(data[pivot_index], data[high]);
  int pivot =data[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (data[j] < pivot) {
      i++;
      std::swap(data[i], data[j]);
    }
  }
  std::swap(data[i + 1], data[high]);  
  return i + 1;
}

void quickSort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int part_index = partition(data, low, high);
        quickSort(data, low, part_index - 1);
        quickSort(data, part_index + 1, high);
    }
}
void merge(std::vector<int>& data, int left, int mid, int right){
  int size1 = mid - left + 1;
  int size2 = right - mid;
  
  std::vector<int> L(size1), R(size2);
  for (int i = 0; i < size1; i++)
    L[i] = data[left + i];
  for (int j = 0; j < size2; j++)
    R[j] = data[mid + 1 + j];
  
  int i = 0;
  int j = 0;
  int k = left;
  while (i < size1 && j < size2) {
    if (L[i] <= R[j]) {
      data[k] = L[i];
      i++;
    }
    else {
      data[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < size1) {
    data[k] = L[i];
    i++;
    k++;
  }
  
  while (j < size2) {
    data[k] = R[j];
    j++;
    k++;
    }
}

void mergeSort(std::vector<int>& data, int left, int right){
  if (left >= right)
    return;
  
  int mid = left + (right - left) / 2;
  mergeSort(data, left, mid);
  mergeSort(data, mid + 1, right);
  merge(data, left, mid, right);
}

void stdSort(std::vector<int>& data){
  std::sort(data.begin(), data.end());
}
