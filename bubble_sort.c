#include <stdio.h>
void swap(int *a, int *b);
void bubble_sort(int arr[], int n);

int main()
{

    int arr[5] = {4, 2, 4, 6, 1};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d, ", arr[i]);
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr + j, arr + j + 1);
}