#include <bits/stdc++.h>
using namespace std;

int *arr, *tree;
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2, Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{

    int tc, n, op;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> op;
        arr = (int *)malloc(sizeof(int) * n);
        tree = (int *)malloc(sizeof(int) * n * 3);
        memset(arr, 0, sizeof(int) * n);

        delete arr;
        delete tree;
    }

    return 0;
}