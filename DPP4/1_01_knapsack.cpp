#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

ll knapsack(ll wt[], ll val[], ll W, ll n)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    else
        return dp[n][W] = knapsack(wt, val, W, n - 1);
}
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
    cout << knapsack(wt, val, W, n);
}
