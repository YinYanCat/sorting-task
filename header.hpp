#ifndef HEADER
#define HEADER

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
#include <chrono>

void insertionSort(std::vector<int>& array);
void mergeSort(std::vector<int>& data);
void quickSort(std::vector<int>& data);
void heapSort(std::vector<int>& data);
void stdSort(std::vector<int>& data);
void countingSort(std::vector<int> &data, int start, int end, int mask);
void par_radixSort(std::vector<int> &data, int start, int end);
void radixSort(std::vector<int> &data);
bool checkSorted(std::vector<int> &data);
int main(int argc, char** argv);

#endif
