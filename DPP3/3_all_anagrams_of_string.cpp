#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

void solve(vector<string> v)
{
    map<map<char, int>, vector<string>> mpVal;
    for (ll i = 0; i < v.size(); i++)
    {
        map<char, int> mp;
        vector<string> temp;
        for (int j = 0; j < v[i].size(); j++)
            mp[v[i][j]]++;
        if (mpVal.find(mp) == mpVal.end())
            temp.push_back(v[i]), mpVal.insert({mp, temp});
        else
            mpVal.find(mp)->second.push_back(v[i]);
    }
    vector<vector<string>> vec;
    for (auto it : mpVal)
        vec.push_back(it.second);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
int32_t main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    solve(s);
}
