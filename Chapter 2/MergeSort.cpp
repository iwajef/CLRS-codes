
/* 
 * @Author: iwajef
 * @Date: 2020-09-20
 * 
 */

#include <cstdio>
#include <cstdlib>
#include <climits>

void MergeSort(int* arr, int left, int right);
void Merge(int* arr, int left, int mid, int right);
void PrintArray(int* arr, int n);


int main()
{
	int arr[10] = {4, 2, 7, 8, 1, 9, 3, 10, 5, 6};
	
	printf("The original array: \n");
	PrintArray(arr, 10);
	
	MergeSort(arr, 0, 9);  // use the merge sort
	
	printf("The array after sorted: \n");
	PrintArray(arr, 10);
	
	return 0;
}


void MergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		// divide the original array to [left ... mid] / [mid+1 ... right] parts and sort separately
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		// merge two sorted arrays
		Merge(arr, left, mid, right);
	}
}


void Merge(int* arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;  // n1, n2 is the element number of arrays L and R
	int n2 = right - mid;
	
	// L.size: arr[left ... mid] + 1(infinite)
	// R.size: arr[mid+1 ... right] + 1(infinite) 
	// DO NOT initialise like this in C: int L[n1 + 1], R[n2 + 1];
	int* L = (int*)malloc(sizeof(int) * (n1 + 1));
	int* R = (int*)malloc(sizeof(int) * (n2 + 1));
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[mid + 1 + i];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	
	// Merge two arrays(L and R) to the original array 'arr' using two pointers
	int i = 0;
	int j = 0;
	for (int k = left; k <= right; k++)
	{
		if (L[i] <= R[j])  // non-descending order
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	// Time Complexity: O(nlogn)
	// Space Complexity: O(n) (new arrays 'L' and 'R')
}


void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
}

