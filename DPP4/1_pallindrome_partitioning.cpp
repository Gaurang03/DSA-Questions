#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

bool pallindrome(string s, ll i, ll j)
{
    while (i <= j)
    {
        if (s[i] == s[j])
            i++, j--;
        else
            return false;
    }
    return true;
}

ll solve(string s, ll i, ll j)
{
    if (i >= j)
        return 0;

    ll mn = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pallindrome(s, i, j))
        return 0;
    for (ll k = i; k < j; k++)
    {
        int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
        mn = min(temp * 1ll, mn * 1ll);
    }
    return dp[i][j] = mn;
}

int32_t main()
{
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, s.size() - 1);
}
