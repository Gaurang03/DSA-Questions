#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    string s, t;
    cin >> s >> t;
    map<ll, ll> mp1, mp2;
    for (ll i = 0; i < s.size(); i++)
        mp1[s[i]]++;
    for (ll i = 0; i < t.size(); i++)
        mp2[s[i]]++;
    if (mp1 == mp2)
        cout << "Isomorphic" << endl;
    else
        cout << "Not Isomorphic" << endl;
}