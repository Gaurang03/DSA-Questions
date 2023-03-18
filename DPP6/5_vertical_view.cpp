#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void verticalView(Node *root)
{
    if (!root)
        return;
    map<int, vector<int>> mp;
    ll hd = 0, mn = 0, mx = 0;
    queue<pair<Node *, ll>> q;
    q.push({root, hd});
    while (!q.empty())
    {
        pair<Node *, ll> temp = q.front();
        q.pop();
        Node *node = temp.first;
        hd = temp.second;
        mp[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
        mn = min(mn, hd);
        mx = max(mx, hd);
    }
    for (ll i = mn; i <= mx; i++)
    {
        for (ll j = 0; j < mp[i].size(); j++)
            cout << mp[i][j] << " ";
        cout << endl;
    }
}

int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    verticalView(root);
    return 0;
}
