#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

int solve(vector<ll> a, ll i, ll j)
{
    if (i >= j)
        return 0;

    ll mn = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];

    for (ll k = i; k < j; k++)
    {
        ll temp = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        mn = min(temp, mn);
    }
    return dp[i][j] = mn;
}
int32_t main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(a, 1, n - 1) << endl;
}
