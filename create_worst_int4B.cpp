#include <iostream>
#include <fstream>

int main(){
  int size = 0;
  std::cout << "array size: "; 
  std::cin >> size;

  if(size>0){
    std::ofstream file("output.bin",std::ios::binary);
    if(!file){
      std::cerr << "error abriendo" << std::endl;
      return 1;
    }
    for(int i=size-1;i>=0;i--){
      file.write(reinterpret_cast<char*>(&i),sizeof(int));
    }
    file.close();
  }

  return 0;
}
