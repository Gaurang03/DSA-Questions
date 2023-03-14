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
    ll val[n], wt[n];
    for (ll i = 0; i < n; i++)
        cin >> val[i];
    for (ll i = 0; i < n; i++)
        cin >> wt[i];
    memset(dp, -1, sizeof(dp));
    ll W;
    cin >> W;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max((val[i - 1] + dp[i][j - wt[i - 1]]), dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][W];
}
