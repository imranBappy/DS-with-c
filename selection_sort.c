#include "swap.h"
#include <stdio.h>

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int selected = i;
        for (int j = i + 1; j < n; j++)
            if (arr[selected] > arr[j])
                selected = j;
        swap(arr + i, arr + selected);
    }
}

int main()
{
    int arr[5] = {4, 2, 4, 6, 1};
    selection_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d, ", arr[i]);
    return 0;
}