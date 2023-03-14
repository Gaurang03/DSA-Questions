#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

ll coinChange(ll a[], int n, int x)
{
    if (dp[n][x] != -1)
        return dp[n][x];
    if (x == 0)
        return dp[n][x] = 1;
    if (x < 0)
        return 0;
    if (n <= 0)
        return 0;
    return dp[n][x] = coinChange(a, n, (x - a[n - 1])) + coinChange(a, n - 1, x);
}

int32_t main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    cout << coinChange(a, n, sum);
    return 0;
}
