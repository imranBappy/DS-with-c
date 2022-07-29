#include "swap.h"
#include <stdio.h>
void insertion_sort(int arr[], int n)
{
    int item, j, i;
    for (i = 1; i < n; i++)
    {
        item = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = item;
    }
}
int main()
{

    int arr[5] = {4, 2, 5, 6, 1};
    insertion_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d, ", arr[i]);

    return 0;
}