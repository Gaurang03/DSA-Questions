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
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    b[0] = a[0];
    for (ll i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    ll round;
    cin >> round;
    for (ll i = 0; i < round; i++)
    {
        ll power;
        cin >> power;
        ll it = upper_bound(a.begin(), a.end(), power) - a.begin();
        it--;
        if (it >= 0)
        {
            cout << it + 1 << " " << b[it] << endl;
        }
    }
}
