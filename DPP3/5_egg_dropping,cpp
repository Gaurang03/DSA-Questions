#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

int solve(int e, int f)
{
    if (e == 1 || f == 0 || f == 1)
        return f;

    ll mn = INT_MAX;
    if (dp[e][f] != -1)
        return dp[e][f];

    for (ll k = e; k < f; k++)
    {
        ll low, high;
        if (dp[e - 1][k - 1] != -1)
            low = dp[e - 1][k - 1];
        else
            low = solve(e - 1, k - 1), dp[e - 1][k - 1] = low;
        if (dp[e][f - k] != -1)
            high = dp[e][f - k];
        else
            high = solve(e, f - k), dp[e][f - k] = high;
        ll temp = 1 + max(low, high);

        // int temp = 1+ max(solve( e-1, k-1) , solve( e,f-k )) ;
        mn = min(temp, mn);
    }
    return dp[e][f] = mn;
}

int32_t main()
{
    ll e, f;
    cin >> e >> f;
    memset(dp, -1, sizeof(dp));
    cout << solve(e, f) << endl;
}
