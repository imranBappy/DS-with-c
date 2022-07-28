#include <stdio.h>

int binary_search(int arr[], int n, int target, int lv, int uv)
{
    if (lv <= uv)
    {
        int mid = (lv + uv) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            binary_search(arr, n, target, lv, mid - 1);
        }
        else
        {
            binary_search(arr, n, target, mid + 1, uv);
        }
    }
    else
    {
        return -1;
    }
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

int main()
{
    int arr[5] = {4, 2, 4, 6, 1};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d, ", arr[i]);

    printf("\n%d\n", binary_search(arr, 5, 1, 0, 4));
    return 0;
}