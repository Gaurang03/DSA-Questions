#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

const int N = 1e5 + 10;

vector<ll> g[N];
bool vis[N];

void dfs(ll vertex)
{
    vis[vertex] = true;
    for (ll child : g[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

int32_t main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    ll ct = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        ct++;
    }
    if (ct == 1)
        cout << "Connected" << endl;
    else
        cout << "Not Connected" << endl;
}
