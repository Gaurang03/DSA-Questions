#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

int32_t main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, 0, sizeof(dp));
    ll total = 0;
    for (ll i = (n - 1); i >= 0; i--)
    {
        total += a[i];
        for (ll j = i; j < n; j++)
            if (i == j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
    cout << (total + dp[0][n - 1]) / 2;
}
