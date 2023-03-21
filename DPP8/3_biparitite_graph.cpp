#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

vector<bool> vis;
vector<vector<int>> adj;
bool bipart;
vector<int> col;
void color(ll u, ll curr)
{
    if (col[u] != -1 and col[u] != curr)
    {
        bipart = false;
        return;
    }
    col[u] = curr;
    if (vis[u])
        return;
    vis[u] = true;
    for (auto i : adj[u])
    {
        color(i, curr xor 1);
    }
}

int32_t main()
{
    bipart = true;
    ll n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
            color(i, 0);
    }
    if (bipart)
        cout << "Biaprtite graph";
    else
        cout << "Not Biaprtite graph";
    return 0;
}