#include "header.hpp"
#include "par_radix.cpp"
#include "sorting_algorithms.cpp"

void readFile(char* filepath, std::vector<int> &data){
  std::ifstream file(filepath);
  if(!file.is_open()){
    std::cerr << "error abriendo" << std::endl;
    return;
  }
  int value;
  
  while(file.read(reinterpret_cast<char*>(&value),sizeof(int))){
    data.push_back(value);
     
  }
  if(file.bad()){
    std::cerr << "error leyendo" << std::endl;
  }
  file.close();
}

bool checkSorted(std::vector<int> &data){
  for(int i=1;i<data.size();i++){
    if(data[i-1]>data[i]){
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv){
  if(argc == 2){
    std::vector<int> data;
    readFile(argv[1],data);

    std::cout << "int quantity: " << data.size() << std::endl;
    
    std::cout << "radix sorting..." << std::endl;
    auto tin = std::chrono::high_resolution_clock::now();
    radixSort(data);
    auto tout = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
    std::cout << "time:" << duration.count() << " ms"<< std::endl;
    std::cout << "sorted: " << checkSorted(data) << std::endl;


    data.clear();
    readFile(argv[1],data);
    
    std::cout << std::endl << std::endl << "heap sorting..." << std::endl;
    tin = std::chrono::high_resolution_clock::now();
    heapSort(data);
    tout = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
    std::cout << "time:" << duration.count() << " ms"<< std::endl;
    std::cout << "sorted: " << checkSorted(data) << std::endl;


    data.clear();
    readFile(argv[1],data);
    
    std::cout << std::endl << std::endl << "insertion sorting..." << std::endl;
    tin = std::chrono::high_resolution_clock::now();
    insertionSort(data);
    tout = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
    std::cout << "time:" << duration.count() << " ms"<< std::endl;
    std::cout << "sorted: " << checkSorted(data) << std::endl;
    
    return 0;
  }
  return 1;
}
