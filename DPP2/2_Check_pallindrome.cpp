#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    string s;
    cin >> s;
    string s1 = s;
    reverse(s.begin(), s.end());
    if (s == s1)
        cout << "Pallindrome Number" << endl;
    else
        cout << "Not Pallindrome Number" << endl;
}
