void countingSort(std::vector<int> &data, int start, int end, int mask){
  std::vector<int> output(end-start);
  std::vector<int> count(2,0);
  for(int i=start;i<end;i++){
    int bit = (data[i]&mask) ? 1 : 0;
    count[bit]++;
  }
  count[1]+=count[0];
  for(int i=end-1;i>=start;i--){
    int bit = (data[i]&mask) ? 1 : 0;
    output[--count[bit]] = data[i];
  }
  for(int i=start;i<end;i++){
    data[i]=output[i-start];
  }
}

void par_radixSort(std::vector<int> &data, int start, int end){
  if(start >= end){
    return;
  }
  int max = data[start];
  for(int i=start;i<end;i++){
    if(data[i]>max){
      max=data[i];
    }
  }
  for(int mask = 1;mask<=max;mask<<=1){
    countingSort(data,start,end,mask);
  }
}

void radixSort(std::vector<int> &data){
  int size = data.size();
  int max_threads = std::thread::hardware_concurrency();
  int optimal_threads = std::min(max_threads,size);
  int min_chunk_size = 128;
  if(optimal_threads == 0){
    optimal_threads = 2;
  }
  int chunk_size=std::max(min_chunk_size,size/optimal_threads);
  int num_threads = (size+chunk_size-1)/chunk_size;
  std::vector<std::thread> threads;

  for(int i=0;i<num_threads;i++){
    int start = i*chunk_size;
    int end = std::min(size,(i+1)*chunk_size);
    threads.emplace_back(par_radixSort, std::ref(data), start, end);
  }
  for(auto &t : threads){
    t.join();
  }

  int current_size = chunk_size;
  while(current_size < size){
    for(int i=0;i<size;i+=2*current_size){
      int mid = std::min(i+current_size, size);
      int right = std::min(i+2*current_size,size);
      std::inplace_merge(data.begin()+i,data.begin()+mid,data.begin()+right);
    }
    current_size *= 2;
  }
}


