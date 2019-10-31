#include <iostream>
using namespace std;

int linearSearch(int arr[], int len, int target)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == target)
			return i;
	}

	return -1;
}

int binSearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == arr[mid])
			return mid;
		else 
		{
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int recBinSearch(int arr[], int first, int last, int target)
{
	int mid = (first + last) / 2;
	
	if (first > last)
		return -1;

	if (target == arr[mid])
		return mid;

	if (target > arr[mid])
		recBinSearch(arr, mid + 1, last, target);
	else
		recBinSearch(arr, first, mid - 1, target);
}