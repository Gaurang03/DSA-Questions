#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    string s;
    cin >> s;
    for (ll i = 0; i < s.size(); i++)
        if (s[i] <= 'o')
            cout << (s[i] - 'a') / 3 + 2 << endl;
        else if (s[i] <= 'v' && s[i] >= 't')
            cout << 8 << endl;
        else if (s[i] >= 'p' && s[i] <= 's')
            cout << 7 << endl;
        else
            cout << 9 << endl;
}