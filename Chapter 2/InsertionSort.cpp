
/* 
 * @Author: iwajef
 * @Date: 2020-09-20
 * 
 */

#include <stdio.h>

void InsertionSort(int* arr, int n);
void PrintArray(int* arr, int n);


int main()
{
	int arr[10] = {4, 2, 7, 8, 1, 9, 3, 10, 5, 6};  // an array that needs to be sorted
	
	printf("The original array: \n");
	PrintArray(arr, 10);
	
	InsertionSort(arr, 10);  // use the insertion sort
	
	printf("The array after sorted: \n");
	PrintArray(arr, 10);
	
	return 0;
}


void InsertionSort(int* arr, int n)
{
	// arr[0...i-1] are already sorted
	// insert arr[i] at the correct index
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];  // key is the current value that is gonna insert to arr[0...i-1]
		int j = i - 1;
		// iterate from i-1 through correct index
		while (j >= 0 && key < arr[j])  // key < arr[j] sorting in non-descending order
		{
			arr[j + 1] = arr[j];  // move the values next to them
			j--;  // j-1 continue the loop
		}
		arr[j + 1] = key;  // j+1 is the correct index to insert the key. PERFECT!!!
	}
	// Time Complexity: O(n^2)
	// Worst Case: O(n^2)
	// Best Case: O(n), the array is already in sorted order, just have to scan the whole array once
	// Space Complexity: O(1)
}


void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
}

