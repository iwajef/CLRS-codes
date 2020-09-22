
/*
 * Author: iwajef
 * Date: 2020-09-20
 */

#include <cstdio>

void InsertionSort(int* arr, int n);
void PrintArray(int* arr, int n);


int main()
{
    int arr[10] = {4, 2, 7, 8, 1, 9, 3, 10, 5, 6};

    printf("The original array: \n");
    PrintArray(arr, 10);

    InsertionSort(arr, 10);

    printf("The array after sorted: \n");
    PrintArray(arr, 10);

    return 0;
}


void InsertionSort(int* arr, int n)
{
    // arr[0 ... i-1] are already sorted
    // insert arr[i] at the correct index
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];  // key is the current value that is going to be inserted to arr[0 ... i-1]
        int j = i - 1;
        // iterate from i-1 through correct index
        while (j >= 0 && key < arr[j])  // key < arr[j] means non-descending order
        {
            arr[j + 1] = arr[j];  // move the values next to them
            j--;
        }
        arr[j + 1] = key;  // j+1 is the correct index to insert the key
    }
}


void PrintArray(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[n - 1]);
}