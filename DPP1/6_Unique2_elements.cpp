#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int setBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int32_t main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll x = 0;
    for (ll i = 0; i < n; i++)
        x ^= a[i];

    ll temp = x, bit = 0, pos = 0;
    while (bit != 1)
    {
        bit = x & 1;
        pos++;
        x >>= 1;
    }

    ll nx = 0;
    for (ll i = 0; i < n; i++)
        if (setBit(a[i], pos - 1))
            nx ^= a[i];

    cout << nx << endl;
    cout << (temp ^ nx) << endl;
}
