#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

ll solve(ll face, ll moves, ll total)
{
    if (total == 0 && moves == 0)
        return 1;

    if (total < 0 || moves == 0)
        return 0;

    if (dp[moves][total] != -1)
        return dp[moves][total];

    ll result = 0;
    for (ll i = 1; i <= face; i++)
        result += solve(face, moves - 1, total - i);
    return dp[moves][total] = result;
}

int32_t main()
{
    ll face, moves, total;
    cin >> face >> moves >> total;
    memset(dp, -1, sizeof(dp));
    cout << solve(face, moves, total) << endl;
}
