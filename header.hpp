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
void merge(std::vector<int>& data, int letf, int mid, int right);
void mergeSort(std::vector<int>& data, int left, int right);
int partition(std::vector<int>& data, int low, int high);
void quickSort(std::vector<int>& data, int low, int high);
void heapSort(std::vector<int>& data);
void stdSort(std::vector<int>& data);
void countingSort(std::vector<int> &data, int start, int end, int shift);
void par_radixSort(std::vector<int> &data, int start, int end);
void radixSort(std::vector<int> &data, bool is_parallel);
bool checkSorted(std::vector<int> &data);
int main(int argc, char** argv);

#endif
