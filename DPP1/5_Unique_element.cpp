#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    ll n;
    cin >> n;
    int a[n], x = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], x ^= a[i];
    cout << x << " ";
}
