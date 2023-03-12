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
    ll last, mx = a[0], mxVal = a[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(a[i], a[i] + mx);
        if (mx > mxVal)
            mxVal = mx, last = i;
    }
    int st = last;
    while (st >= 0)
    {
        mxVal -= a[st];
        if (mxVal == 0)
            break;
        st--;
    }
    for (int i = st; i <= last; i++)
        cout << a[i] << " ";
}
