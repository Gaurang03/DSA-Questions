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

void topView(Node *root)
{
    vector<ll> res;
    map<ll, ll> mp;
    queue<pair<Node *, ll>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        Node *curr = x.first;
        ll i = x.second;
        if (mp.find(i) == mp.end())
            mp[i] = curr->data;
        if (curr->left)
            q.push({curr->left, i - 1});
        if (curr->right)
            q.push({curr->right, i + 1});
    }
    for (auto i : mp)
        cout << i.second << " ";
}

void bottomView(Node *root)
{
    map<ll, ll> mp;
    vector<ll> v;
    queue<pair<Node *, ll>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        Node *curr = x.first;
        ll i = x.second;
        mp[i] = curr->data;
        if (curr->left)
            q.push({curr->left, i - 1});
        if (curr->right)
            q.push({curr->right, i + 1});
    }
    for (auto i : mp)
        cout << i.second << " ";
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
    topView(root);
    cout << endl;
    bottomView(root);
    return 0;
}
