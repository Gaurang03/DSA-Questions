#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

ll n;
void setBit(ll pos)
{
    n = n | (1 << pos);
}

bool getBit(ll pos)
{
    return ((n & (1 << pos)) != 0);
}

bool clearBit(ll pos)
{
    return ((n & ~(1 << pos)));
}

ll clearRightmostBit()
{
    return (n & (n - 1));
}

ll only_rightmost_active()
{
    ll pos = 0, c = 0;
    while (n != 0)
    {
        if (getBit(pos))
            break;
        c++;
        pos++;
    }
    return 1 << c;
}

int32_t main()
{
    cin >> n;
    setBit(1);
    cout << n << endl;
    cout << getBit(3) << endl;
    cout << clearBit(1) << endl;
    cout << clearRightmostBit() << endl;
    cout << only_rightmost_active() << endl;
}
