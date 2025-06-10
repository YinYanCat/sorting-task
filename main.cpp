#include "header.hpp" // Incluir encabezado con declaraciones compartidas (vectores, funciones, etc.)
#include "par_radix.cpp" // Incluir implementación de radix sort paralelo
#include "sorting_algorithms.cpp" // Incluir implementación de otros algoritmos de ordenamiento


// Lee un archivo binario de enteros y carga los datos en un vector
void readFile(char* filepath, std::vector<int> &data){
  std::ifstream file(filepath);
  if(!file.is_open()){
    std::cerr << "error abriendo" << std::endl;
    return;
  }
  int value;
  // Leer enteros del archivo binario y agregarlos al vector
  while(file.read(reinterpret_cast<char*>(&value),sizeof(int))){
    data.push_back(value);
     
  }
  if(file.bad()){
    std::cerr << "error leyendo" << std::endl;
  }
  file.close();
}

// Verifica si el vector está ordenado en forma ascendente
bool checkSorted(std::vector<int> &data){
  for(int i=1;i<data.size();i++){
    if(data[i-1]>data[i]){
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv){
  
  if(argc >= 2){ // Asegura que se recibió un argumento (nombre del archivo)
    std::vector<int> original; // Vector para almacenar los datos originales
    std::vector<int> data; // Vector para trabajar con los datos durante pruebas
    readFile(argv[1],original);

    const bool skipQuick = (argc >= 3 && std::string(argv[2]) == "-q");
    const bool skipInsertion = (argc >= 3 && std::string(argv[2]) == "-i");
    
    // Abrir archivo CSV para escribir los tiempos de ejecución
    std::ofstream rfile;
    rfile.open((std::filesystem::path(argv[1])).string()+"_times.csv");

    // Variables para medir tiempo de ejecución
    std::chrono::time_point<std::chrono::high_resolution_clock> tin;
    std::chrono::time_point<std::chrono::high_resolution_clock> tout;
    std::chrono::milliseconds duration;

    // Mostrar cantidad de enteros leídos
    std::cout << "int quantity: " << original.size() << std::endl;

    auto runSort = [&](const std::string &name, auto sortFunc, bool enabled = true){
      std::cout << "\n\n" << name << "..." << std::endl;
      rfile << "\n" << name << ":,";
      if(!enabled){
	rfile << "skipped,";
	return;
      }
      for(int i=0; i<20; i++){
        data = original;
	tin = std::chrono::high_resolution_clock::now();
	sortFunc(data);
	tout = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(tout - tin);
	rfile << duration.count() << ",";
      }
    };

    runSort("Parallel radix sorting", [&](std::vector<int>& d){ radixSort(d, true); });
    runSort("Radix sorting", [&](std::vector<int>& d){ radixSort(d, false); });
    runSort("STD sorting", stdSort);
    runSort("Heap sorting", heapSort);
    runSort("Merge sorting", [&](std::vector<int>& d){ mergeSort(d, 0, d.size() - 1); });
    runSort("Quick sorting", [&](std::vector<int>& d){ quickSort(d, 0, d.size() - 1); }, !skipQuick);
    runSort("Insertion sorting", insertionSort, !(skipInsertion || skipQuick));

    rfile.close();
    return 0;
  }
  return 1;
}
