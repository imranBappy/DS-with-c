#include "swap.h"
#include <stdio.h>

void bubble_sort(int arr[], int n);
int main()
{

    int arr[5] = {1, 2, 3, 5, 4};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d, ", arr[i]);
    return 0;
}

void bubble_sort(int arr[], int n)
{
    int is_sorted = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
                is_sorted = 0;
            }
        }
        if (is_sorted)
            return;
        is_sorted = 1;
    }
}