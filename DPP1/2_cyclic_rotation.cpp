#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

#define sz(x) (int)(x).size()

int32_t main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll store = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = store;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
