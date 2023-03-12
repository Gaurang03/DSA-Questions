#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// typedef __int128 ll;
const long long ONE_SIXTH = 166666668;

#define sz(x) (int)(x).size()

int32_t main()
{
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        a[i] = a[(i + d) % n];
    }
    for (int i = 0; i < n - d; i++)
        cout << a[i] << " ";
}
