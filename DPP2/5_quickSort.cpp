#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

ll partition(ll a[], ll l, ll r)
{
    ll pivot = a[r];
    ll i = l - 1;

    for (ll j = l; j < r; j++)
        if (a[j] < pivot)
            i++, swap(a[i], a[j]);

    swap(a[i + 1], a[r]);
    return i + 1;
}
void quickSort(ll a[], ll l, ll r)
{
    while (l < r)
    {
        ll p = partition(a, l, r);

        if (p - l < r - p)
            quickSort(a, l, p - 1), l = p + 1;
        else
            quickSort(a, p + 1, r), r = p - 1;
    }
}

int32_t main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n);
    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";
}