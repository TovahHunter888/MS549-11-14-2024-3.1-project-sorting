#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <list>
using namespace std;

void quickSort_Vector(std::vector<int>& vec, int low, int high);
void merge(int list1[], int list1Size, int list2[], int list2Size, int temp[]);
void MergeSort_list(std::list<int>& lst);
void printArray(const std::vector<int>& arr);
void test_sorting(int dataset_size);