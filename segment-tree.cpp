#include <bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx] = {0, 4, 1, 3, 7, 1, 0, 2};
int tree[mx * 3];

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
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j) // b >= i && e <= j / b <= i && j <= e
        return tree[node];
    int Left = node * 2, Right = node * 2 + 1;
    int mid = (b + e) / 2;
    return query(Left, b, mid, i, j) + query(Right, mid + 1, e, i, j);
}

int update(int node, int b, int e, int i, int value)
{
    if (e == b)
    {
        tree[node] = value;
        return 0;
    }
    int Left = node * 2, Right = node * 2 + 1;
    int mid = (b + e) / 2;

    if (i > mid)
        query(Right, mid + 1, e, i, value);
    else
        query(Left, b, mid, i, value);
    tree[node] = tree[Left] + tree[Right];
}

int main()
{

    int n = 7;
    init(1, 1, n);
    for (int i = 0; i <= 13; i++)
    {
        cout << tree[i] << ", ";
    }
    cout << endl
         << endl;

    cout << query(1, 1, 7, 1, 4) << endl;

    return 0;
}