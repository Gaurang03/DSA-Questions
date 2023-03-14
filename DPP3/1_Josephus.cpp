#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll dp[1001][1001];

int32_t main()
{
    ll n, rot;
    cin >> n >> rot;
    ll i = 1, result = 0;
    while (i <= n)
    {
        result = (result + rot) % i++;
    }
    cout << result + 1 << endl;
}
