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

int maxPathSum(Node *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left = maxPathSum(root->left, ans);
    int right = maxPathSum(root->right, ans);
    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    int ans = INT_MIN;

    cout << maxPathSum(root, ans) << endl;
}
