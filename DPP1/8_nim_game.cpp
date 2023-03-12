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
    {
        x ^= a[i];
    }
    if (x)
        cout << "A is Winner" << endl;
    else
        cout << "B is Winner" << endl;
}
