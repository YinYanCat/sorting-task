#include <iostream>
#include <fstream>

int main() {
    int size = 0;
    std::cout << "array size x with x = ";
    std::cin >> size;

    std::ofstream file("decrec_"+std::to_string(size*sizeof(int)/1000000)+"MB.bin", std::ios::binary);
    if (!file) {
      std::cerr << "Error al abrir el archivo" << std::endl;
      return 1;
    }
    
    for (int i = size - 1; i >= 0; --i) { 
      file.write(reinterpret_cast<const char*>(&i), sizeof(int));
    }
    
    file.close();
    std::cout << "Archivo generado con " << size * sizeof(int) << "bytes, enteros decrecientes." << std::endl;
    
    return 0;
}

