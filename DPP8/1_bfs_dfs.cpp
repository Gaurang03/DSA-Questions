#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

const int N = 1e5 + 10;

vector<ll> g[N];
bool vis[N], lvl[N];

void dfs(ll vertex)
{
    cout << vertex << endl;
    vis[vertex] = true;
    for (ll child : g[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

void bfs(ll source)
{
    queue<ll> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        ll cur_v = q.front();
        q.pop();
        cout << cur_v << " ";
        for (auto child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                lvl[child] = lvl[cur_v] + 1;
            }
        }
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
    dfs(1);
    cout << endl;
    bfs(1);
}
