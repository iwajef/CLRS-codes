
/*
 * Author: iwajef
 * Date: 2020-09-21
 */

#include <cstdio>

void HeapSort(int* arr, int length);
void BuildMaxHeap(int* arr, int length);
void MaxHeapify(int* arr, int i);
void swap(int& a, int& b);
void PrintArray(int* arr, int start, int end);


int main()
{
    int arr[11] = {0, 4, 2, 7, 8, 1, 9, 3, 10, 5, 6};  // arr[0] must be 0 when initialized

    arr[0] = sizeof(arr) / sizeof(int) - 1;  // let arr[0] be heap-size
    printf("The original array: \n");
    PrintArray(arr, 1, 10);

    HeapSort(arr, arr[0]);

    printf("The array after sorted: \n");
    PrintArray(arr, 1, 10);

    return 0;
}


void HeapSort(int* arr, int length)
{
    BuildMaxHeap(arr, arr[0]);  // first create one max heap
                                // the first element(arr[1]) will be the largest element in the array
    for (int i = length; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        arr[0]--;  // heap size -1
        MaxHeapify(arr, 1);
    }
}


void BuildMaxHeap(int* arr, int length)
{
    arr[0] = length;
    // arr[n / 2 + 1] arr[n / 2 + 2] ... arr[n] will be leaf nodes
    for (int i = length / 2; i >= 1; i--)
        MaxHeapify(arr, i);
}


void MaxHeapify(int* arr, int i)
{
    int l = i * 2;  // l = LEFT(i)
    int r = i * 2 + 1;  // r = RIGHT(i)
    int largest;  // largest index of max(arr[i], arr[l], arr[r])
    // l <= arr[0] guarantees that i is not a leaf node
    // same for r <= arr[0]
    if (l <= arr[0] && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r <= arr[0] && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest);
    }
}


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void PrintArray(int* arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[end]);
}
