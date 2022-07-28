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

int main()
{
    int arr[5] = {1,4,5,7,9};
    
    printf("%d\n", binary_search(arr, 5, 9, 0,4));
    return 0;
}