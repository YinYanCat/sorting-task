#include <iostream>
#include <fstream>
#include <string>

int main() {
    int size = 0;
    std::cout << "array size x with x = ";
    std::cin >> size;


    std::ofstream file("crec_"+std::to_string(size*sizeof(int)/1000000)+"MB.bin", std::ios::binary);
    if (!file) {
      std::cerr << "Error al abrir el archivo" << std::endl;
      return 1;
    }
    
    for (int i = 0; i<size; i++) {  // De 0 hasta size
      file.write(reinterpret_cast<const char*>(&i), sizeof(int));
    }
    
    file.close();
    std::cout << "Archivo generado con tamaño " << size*sizeof(int) << "bytes, enteros crecientes." << std::endl;


    return 0;
}

