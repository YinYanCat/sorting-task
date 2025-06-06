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

void insertionSort(std::vector<int>& data){
  std::vector<int> priority;
  priority.push_back(data[0]);
  for(int i=1;i<data.size();i++){
    bool inserted = false;
    for(int j=0;j<priority.size();j++){
      if(data[i]<priority[j]){
	priority.insert(priority.begin()+j,data[i]);
	inserted = true;
	break;
      }
    }
    if(!inserted){
      priority.push_back(data[i]);
    }
  }
  for(int i=0;i<data.size();i++){
    data[i]=priority[i];
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

void mergeSort(std::vector<int>& data){
}
