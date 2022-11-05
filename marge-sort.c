#include <stdio.h>

void print_arr(int arr[], int n);
void marge(int arr[], int left, int mid, int right);
void marge_sort(int arr[], int left, int right);

void marge(int arr[], int left, int mid, int right)
{
    int n = right - left;
    int i = 0, l = left, r = mid;
    int newArr[n];
    for (i = 0; (l <= mid && r <= right); i++)
    {
        if (arr[l] < arr[r])
            newArr[i] = arr[l++];
        else
            newArr[i] = arr[r++];
    }
    while (l <= mid)
        newArr[i++] = arr[l++];
    while (r <= right)
        newArr[i++] = arr[r++];
    for (i = 0; i <= n; i++)
        arr[left++] = newArr[i];
}
void marge_sort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    marge_sort(arr, left, mid);
    marge_sort(arr, mid + 1, right);
    marge(arr, left, mid + 1, right);
}

void print_arr(int arr[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[i]);
}

int main()
{

    // int arr[] = {1, 5, 6, 2, 3, 4};
    int arr[] = {5, 2, 6, 3, 1, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    print_arr(arr, n);

    // int mid = (0 + n) / 2;
    marge_sort(arr, 0, n - 1);
    printf("After : ");
    // marge(arr, 0, mid, n - 1);
    print_arr(arr, n);

    return 0;
}