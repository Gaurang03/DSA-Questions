#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

ll lcs(string a, string b, ll n, ll m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (a[n - 1] == b[m - 1])
        return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1);
    else
        return dp[n][m] = max(lcs(a, b, n, m - 1), lcs(a, b, n - 1, m));
}

int32_t main()
{
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    ll m = a.size(), n = b.size();
    cout << lcs(a, b, n, m) << endl;
}
