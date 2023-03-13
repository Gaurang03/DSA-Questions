#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
ll val;

ll fact(ll n, ll k)
{
    if (n == 0)
        return 1;
    val = val * k;
    fact(n - 1, k + 1);
}

int32_t main()
{
    val = 1;
    ll s;
    cin >> s;
    fact(s, 1);
    cout << val;
}
