
/*
 * Author: iwajef
 * Date: 2020-09-20
 */

#include <cstdio>
#include <cstdlib>
#include <climits>

void MergeSort(int* arr, int p, int r);
void Merge(int* arr, int p, int q, int r);
void PrintArray(int* arr, int n);


int main()
{
    int arr[10] = {4, 2, 7, 8, 1, 9, 3, 10, 5, 6};

    printf("The original array: \n");
    PrintArray(arr, 10);

    MergeSort(arr, 0, 9);

    printf("The array after sorted: \n");
    PrintArray(arr, 10);

    return 0;
}


void MergeSort(int* arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        // divide the original array to [p ... q] and [q+1 ... r]
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        // merge two sorted arrays
        Merge(arr, p, q, r);
    }
}


void Merge(int* arr, int p, int q, int r)
{
    // n1, n2 is the size of arrays L, R
    int n1 = q - p + 1;
    int n2 = r - q;
    // don't forget to add the size by 1 to append additional INT_MAX
    int* L = (int*)malloc(sizeof(int) * (n1 + 1));
    int* R = (int*)malloc(sizeof(int) * (n2 + 1));
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[q + 1 + i];
    L[n1] = INT_MAX; R[n2] = INT_MAX;

    // Merge two arrays L, R to the original array (arr)
    int i = 0; int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
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
}


void PrintArray(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[n - 1]);
}