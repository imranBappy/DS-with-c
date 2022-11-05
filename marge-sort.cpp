#include <bits/stdc++.h>
using namespace std;
void merge(int A[], int left, int mid, int right);
void merge_sort(int A[], int left, int right);
void print_arr(int arr[], int len);
int main()
{
    int left = 0, right = 9;
    int A[] = {10, 1, 6, 5, 3, 8, 4, 7, 2, 9};
    merge_sort(A, left, right);
    print_arr(A, 10);
    return 0;
}

void merge_sort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);

    merge(A, left, mid, right);
}
void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}
void merge(int A[], int left, int mid, int right)
{
    int i;
    int index_a, index_l, index_r;
    int size_left, size_right;

    size_left = mid - left + 1; // size of L array
    size_right = right - mid;   // size of R array

    int L[size_left], R[size_right];

    // copy element from A arry to L and R array
    for (i = 0; i < size_left; i++)
        L[i] = A[left + i];
    for (i = 0; i < size_right; i++)
        R[i] = A[right + i];
    index_l = 0;
    index_r = 0;
    for (index_a = left; index_l < size_left && index_r < size_right; index_a++)
    {

        if (L[index_l] < R[index_r])
        {
            A[index_a] = L[index_l];
            index_l++;
        }
        else
        {
            A[index_a] = R[index_r];
            index_r++;
        }
    }

    while (index_l < size_left)
    {
        A[index_a] = L[index_l];
        index_a++;
        index_l++;
    }

    while (index_r < size_right)
    {
        A[index_a] = R[index_r];
        index_a++;
        index_r++;
    }
}