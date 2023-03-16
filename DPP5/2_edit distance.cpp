#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = b.size();

    vector<int> f(n + 1), s(n + 1);

    for (int i = 0; i <= n; i++)
        f[i] = i;

    for (int i = 1; i <= m; i++)
    {
        s[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                s[j] = f[j - 1];
            else
                s[j] = 1 + min(min(f[j - 1], f[j]), s[j - 1]);
        }
        f = s;
    }
    cout << f[n] << endl;
}
