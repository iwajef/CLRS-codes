
/*
 * Author: iwajef
 * Date: 2020-09-22
 */

#include <cstdio>

void QuickSort(int* arr, int p, int r);
int Partition(int* arr, int p, int r);
void swap(int& a, int& b);
void PrintArray(int* arr, int n);


int main()
{
    int arr[10] = {4, 2, 7, 8, 1, 9, 3, 10, 5, 6};

    printf("The original array: \n");
    PrintArray(arr, 10);

    QuickSort(arr, 0, 9);

    printf("The array after sorted: \n");
    PrintArray(arr, 10);

    return 0;
}


void QuickSort(int* arr, int p, int r)
{
    if (p < r)
    {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}


int Partition(int* arr, int p, int r)
{
    int x = arr[r];  // x is the pivot element
                     // numbers which are less than x are going to be on the left part
                     // same for numbers greater than x, they are going to be on the right part
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void PrintArray(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[n - 1]);
}
