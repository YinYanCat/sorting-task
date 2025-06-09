#include <iostream>
#include <fstream>
#include <ctime>


int main() {
  std::srand(std::time(nullptr));
  int size = 0;
  std::cout << "array size x with x = ";
  std::cin >> size;
  
  std::ofstream file("rand_"+std::to_string(size)+"size.bin", std::ios::binary);
  if (!file) {
    std::cerr << "Error al abrir el archivo" << std::endl;
    return 1;
  }
  
  for (int i = size - 1; i >= 0; --i) {
    int x = std::rand()%size;
    file.write(reinterpret_cast<const char*>(&x), sizeof(int));
  }
  
  file.close();
  std::cout << "Archivo generado con " << size << " enteros decrecientes." << std::endl;
  
  return 0;
}

