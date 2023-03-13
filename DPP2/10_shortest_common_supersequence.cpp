#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

int32_t main()
{
    string a, b;
    cin >> a >> b;
    int m = b.size(), n = a.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    ll i = n, j = m;
    string v;
    while (i && j)
    {
        if (a[i - 1] == b[j - 1])
            v += a[i - 1], i--, j--;
        else if (dp[i - 1][j] < dp[i][j - 1])
            v += b[j - 1], j--;
        else
            v += a[i - 1], i--;
    }
    while (i != 0)
        v += a[--i];
    while (j != 0)
        v += b[--j];

    reverse(v.begin(), v.end());
    cout << v << endl;
}
