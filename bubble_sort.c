#include <stdio.h>
#include "swap.h"


void bubble_sort(int arr[], int n);
int main()
{


    return 0;
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr + j, arr + j + 1);
}