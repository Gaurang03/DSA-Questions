#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par)
{
    vis[vertex] = true;
    bool isLoopExists = false;

    for (int child : g[vertex])
    {

        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return true;
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;
}

int32_t main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool isLoopExists = false;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl;
}