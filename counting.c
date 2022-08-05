#include <stdio.h>
#include <stdlib.h>
int *counting_sort(int arr[], int n, int max)
{
    int count[max + 1];
    int sum[max + 1];
    int *output = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    sum[0] = count[0];
    for (int i = 1; i < max + 1; i++)
        sum[i] = count[i] + sum[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        int k = arr[i];
        output[sum[k] - 1] = arr[i];
        sum[k] = sum[k] - 1;
    }
    return output;
}

int main()
{
    int arr[] = {1, 2, 5, 9, 2, 6, 5, 4};
    int *output = counting_sort(arr, 8, 9);
    for (int i = 0; i < 8; i++)
    {
        printf("%d, ", output[i]);
    }
    return 0;
}