#include "header.hpp"

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
