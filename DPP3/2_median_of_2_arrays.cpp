#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

ll solve(vector<ll> a, vector<ll> b, ll n)
{
    ll t = 2 * n, k = (t + 1) / 2;
    ll l = max(0ll, k - n), r = min(n, k);
    while (l <= r)
    {
        ll partition1 = (l + r) / 2;
        ll partition2 = k - partition1;

        ll l1 = partition1 == 0 ? INT_MIN : a[partition1 - 1];
        ll l2 = partition2 == 0 ? INT_MIN : b[partition2 - 1];
        ll r1 = partition1 == n ? INT_MAX : a[partition1];
        ll r2 = partition2 == n ? INT_MAX : b[partition2];

        if (l1 <= r2 && l2 <= r1)
            return (t % 2 == 0) ? (max(l1, l2) + min(r1, r2)) / 2.000 : max(l1, l2);
        else if (l1 > r2)
            r = partition1 - 1;
        else
            l = partition1 + 1;
    }
}

int32_t main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    cout << solve(a, b, n) << endl;
}
