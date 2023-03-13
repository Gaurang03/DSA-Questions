#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];

    for (ll i = 0; i < n; i++)
        for (ll j = i; j < n; j++)
            swap(a[i][j], a[j][i]);

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n / 2; j++)
            swap(a[j][i], a[n - j - 1][i]);

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
