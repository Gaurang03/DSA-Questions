#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const long long ONE_SIXTH = 166666668;

struct Node
{
    ll data;
    struct Node *left;
    struct Node *right;
    Node(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void traverse(Node *root, ll level, auto &mp)
{
    if (root == NULL)
        return;
    if (level & 1)
    {
        mp[level].push_back(root->data);
    }
    else
    {
        mp[level].push_front(root->data);
    }
    traverse(root->left, level + 1, mp);
    traverse(root->right, level + 1, mp);
}

int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    unordered_map<ll, list<ll>> mp;
    traverse(root, 1, mp);
    for (ll i = 1; mp[i].size() > 0; i++)
    {
        cout << "Level " << i << ": ";
        for (ll j : mp[i])
            cout << j << " ";
        cout << endl;
    }
}
