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
    ll sum;
    cin >> sum;
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= sum; j++)
            dp[i][j] = INT_MAX;
    for (ll i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            if (j < a[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - a[i - 1]]);
        }
    }
    cout << dp[n][sum];
    return 0;
}
