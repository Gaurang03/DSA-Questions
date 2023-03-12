#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    ll n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int i = 0, j = m - 1, k = 0, l = n - 1;
    vector<int> v;
    while (i <= j && k <= l)
    {
        for (int m = i; m <= j; m++)
            v.push_back(a[k][m]);
        k++;
        for (int m = k; m <= l; m++)
            v.push_back(a[m][j]);
        j--;
        for (int m = j; m >= i; m--)
            v.push_back(a[l][m]);
        l--;
        for (int m = l; m >= k; m--)
            v.push_back(a[m][i]);
        i++;
    }
    int sz = v.size();
    while (sz != n * m)
    {
        v.pop_back();
        sz--;
    }

    for (int i = 0; i < n * m; i++)
        cout << v[i] << " ";
}
