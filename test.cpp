
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n, u;
        cin >> n >> u;
        int a[n] = {0};
        int d[n + 1] = {0};

        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                d[i] = a[i];
            else
                d[i] = a[i] - a[i - 1];
        }

        for (int i = 0; i < u; i++)
        {
            int l, r, val;
            cin >> l >> r >> val;

            d[l] = d[l] + val;
            d[r + 1] = d[r + 1] - val;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                a[i] = d[i];
            else
            {
                a[i] = d[i] + d[i - 1];
                d[i] = d[i] + d[i - 1];
            }
        }

        int q, b;
        scanf("%d", &q);

        for (int i = 0; i < q; i++)
        {
            scanf("%d", &b);

            printf("%d\n", a[b]);
        }
    }

    return 0;
}
