#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

int32_t main()
{
    string s, s1;
    cin >> s;
    s1 = s;
    reverse(s1.begin(), s1.end());
    int m = s1.size(), n = s.size();
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s[i - 1] == s1[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << endl;
}
