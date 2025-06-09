#include <iostream>
#include <fstream>

int main() {
    int size = 0;
    std::cout << "array size 2^x with x = ";
    std::cin >> size;

    if (size > 0 && size < 31) { // evitar overflow de 1 << 31
        std::ofstream file("output.bin", std::ios::binary);
        if (!file) {
            std::cerr << "Error al abrir el archivo" << std::endl;
            return 1;
        }

        int total = 1 << size;  // Calcula 2^x
        for (int i = total - 1; i >= 0; --i) {  // De 2^x - 1 hasta 0 (inclusive)
            file.write(reinterpret_cast<const char*>(&i), sizeof(int));
        }

        file.close();
        std::cout << "Archivo generado con " << total << " enteros decrecientes." << std::endl;
    } else {
        std::cerr << "x fuera de rango válido (1 <= x < 31)" << std::endl;
    }

    return 0;
}

