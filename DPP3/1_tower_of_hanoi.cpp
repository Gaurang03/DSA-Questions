#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

void towerofHanoi(ll n, char src, char dest, char helper)
{
    if (n == 0)
        return;
    towerofHanoi(n - 1, src, helper, dest);
    cout << "move from " << src << " to " << dest << endl;
    towerofHanoi(n - 1, helper, dest, src);
}

int32_t main()
{
    ll n;
    cin >> n;
    towerofHanoi(4, 'A', 'C', 'B');
}
