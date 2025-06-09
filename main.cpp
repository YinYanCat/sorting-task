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
    std::vector<int> original;
    std::vector<int> data;
    readFile(argv[1],original);

    std::ofstream rfile;
    rfile.open("1MB_Rand.csv");

    auto tin = std::chrono::high_resolution_clock::now();
    auto tout = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);

    std::cout << "int quantity: " << original.size() << std::endl;

    std::cout << "std in-place merge parallelized 16-bit bucket radix sorting..." << std::endl;
    rfile << "Bucket radix sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;
      
      tin = std::chrono::high_resolution_clock::now();
      radixSort(data,true);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile << duration.count() << ",";
    }

    std::cout << std::endl << std::endl << "radix sorting single thread..." << std::endl;
    rfile << "\nRadix sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;
      
      tin = std::chrono::high_resolution_clock::now();
      radixSort(data,false);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile << duration.count() << ",";
    }

    std::cout << std::endl << std::endl << "std sorting..." << std::endl;
    rfile << "\nSTD sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;
      
      tin = std::chrono::high_resolution_clock::now();
      stdSort(data);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile << duration.count() << ",";
    }

    std::cout << std::endl << std::endl << "heap sorting..." << std::endl;
    rfile << "\nHeap sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;

      tin = std::chrono::high_resolution_clock::now();
      heapSort(data);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile  << duration.count() << ",";
    }

    std::cout << std::endl << std::endl << "merge sorting..." << std::endl;
    rfile << "\nMerge sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;
      
      tin = std::chrono::high_resolution_clock::now();
      mergeSort(data, 0, data.size()-1);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile << duration.count() << ",";
    }

    std::srand(std::time(nullptr));
    std::cout << std::endl << std::endl << "quick sorting..." << std::endl;
    rfile << "\nQuick sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;
      
      tin = std::chrono::high_resolution_clock::now();
      quickSort(data, 0, data.size()-1);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile << duration.count() << ",";
    }

    std::cout << std::endl << std::endl << "insertion sorting..." << std::endl;
    rfile << "\nInsertion sortig:,";
    for(int iter=0; iter<20; iter++) {
      data = original;
    
      tin = std::chrono::high_resolution_clock::now();
      insertionSort(data);
      tout = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout-tin);
    
      rfile << duration.count() << ",";
    }

    rfile.close();
    
    return 0;
  }
  return 1;
}
