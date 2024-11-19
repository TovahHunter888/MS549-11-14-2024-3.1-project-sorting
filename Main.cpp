/*Tovah Hunter
* 11/14/2024
* 3.1 Project Sorting
* Estimate 20 hours
* Actual 30 hours
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cstdlib>
#include "sortfunctions.h"
#include <list>
using namespace std;

int main()
{
	// Run performance testing
	int dataset_size[] = { 100, 1000, 10000, 100000 };

	for (int size : dataset_size)
	{
		test_sorting(size);
	}

	return 0;
}

