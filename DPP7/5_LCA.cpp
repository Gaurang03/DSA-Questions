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

Node *LCA(Node *root, ll n1, ll n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    else
        return right;
}

int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    cout << "Enter the nodes for which lca is to be found:" << endl;
    ll n1, n2;
    cin >> n1 >> n2;
    Node *lca = LCA(root, n1, n2);
    if (lca->data == -1)
        cout << "LCA doesn't exit";
    else
        cout << "LCA:" << lca->data;
    return 0;
}
