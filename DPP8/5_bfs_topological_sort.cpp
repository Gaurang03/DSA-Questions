#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

int32_t main()
{
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    vector<vector<ll>> adj(n);
    vector<ll> indeg(n, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<ll> pq;
    for (ll i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        cnt++;
        ll x = pq.front();
        pq.pop();
        cout << x << " ";
        for (auto it : adj[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                pq.push(it);
            }
        }
    }
}