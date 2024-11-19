#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cstdlib>
#include "sortfunctions.h"
#include <list>
using namespace std;

// Generate random array number generator function
std::vector<int> generateRandomArray(int size)
{
	vector<int>arr(5);
	random_device rd;
	mt19937 rng(rd()); // random number generator
	uniform_int_distribution<int> dist(100, 100000); // range of random numbers
	
	for (int& num : arr)
	{
		num = dist(rng);
	}

	return arr;
}

//QuickSort for vector implementation
void quickSort_Vector(std::vector<int>& vec, int low, int high)
{
	 if (low < high)
	 {
		 int pivot = vec[high];// pivot point
		 int i = (low - 1);

		 // loop the array
		 for (int j = low; j < high; j++)
		 {
			 if (vec[j] < pivot)
			 {
				 i++;
				 std::swap(vec[i], vec[j]); // swap elements
			 }
		 }
		 // place pivot in position
		 std::swap(vec[i + 1], vec[high]);
		
		 // Recursion
		 int pi = i + 1;// final position of pivot
		 quickSort_Vector(vec, low, pi - 1);
		 quickSort_Vector(vec, pi + 1, high);
	
	 }
}

//merge two sorted arrays into a temporary array
void merge(int list1[], int list1Size, int list2[], int list2Size, int temp[])
{
	int i = 0, j = 0, k = 0;
	
	// merge the two array halves into the temp array
	while (i < list1Size && j < list2Size)
	{
		if (list1[i] < list2[j]) 
		{
			temp[k++] = list1[i++];
		}
		else 
		{
			temp[k++] = list2[j++];
		}
	}

	// copy remaining elements from list1[]
	while (i < list1Size)
	{
		temp[k++] = list1[i++];
	}

	// copy remaing elements from list2[]
	while (j < list2Size)
	{
		temp[k++] = list2[j++];
	}
}

void MergeSort_list(std::list<int>& lst)
{
	if (lst.size() <= 1)
	{
		return;
	}

		// find middle of the list using an iterator
		auto mid = lst.begin();
		std::advance(mid, lst.size() / 2);

		// split list into two halves
		std::list<int> left(lst.begin(), mid);
		std::list<int> right(mid, lst.end());

		// Recursitive sort the two halves
		MergeSort_list(left);
		MergeSort_list(right);

		// merge two sorted halves
		lst.clear();
		auto left_it = left.begin(), right_it = right.begin();
		while (left_it != left.end() && right_it !=right.end())
		{
			if (*left_it < *right_it)
			{
				lst.push_back(*left_it++);
			}
			else
			{
				lst.push_back(*right_it++);
			}
	    }

		// Add any remaining elements
		lst.insert(lst.end(), left_it, left.end());
		lst.insert(lst.end(), right_it, right.end());
}
// function for debugging
void printArray(const std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
// test the sorting algorithms
void test_sorting(int dataset_size)
{
	//genrate random numbers
	std::vector<int> vec(dataset_size);
	std::mt19937 rng(std::random_device{}()); // random number generator
	std::uniform_int_distribution<int> dist(1, 100000); // range of random numbers

	for (int& num : vec)
	{
		num = dist(rng);
	}
	// test QuickSort
	auto vec_copy = vec; //Reset Quicksort data
	auto start_quick = std::chrono::high_resolution_clock::now();
	quickSort_Vector(vec_copy, 0, dataset_size - 1);
	auto end_quick = std::chrono::high_resolution_clock::now();
	cout << "Vector QuickSort Time for " << dataset_size << " elements: "
		 << std::chrono::duration_cast<std::chrono::milliseconds >(end_quick - start_quick).count() << " ms\n";

	//test Merge Sort
	std::list<int> lst(vec.begin(), vec.end()); //data reset
	auto start_merge_list = std::chrono::high_resolution_clock::now();
	MergeSort_list(lst);
	auto end_merge_list = std::chrono::high_resolution_clock::now();
	std::cout << " List MergeSort Time for " << dataset_size << " elements: "
		 << chrono::duration_cast<chrono::milliseconds > (end_merge_list - start_merge_list).count() << " ms\n";
}