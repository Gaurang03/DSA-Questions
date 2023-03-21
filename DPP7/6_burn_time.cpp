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
ll answer = 0;
ll burnTime(Node *root, ll leaf, ll &dist)
{
    if (root == NULL)
        return 0;
    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }
    ll leftDist = -1, rightDist = -1;
    int lh = burnTime(root->left, leaf, leftDist);
    int rh = burnTime(root->right, leaf, rightDist);

    if (leftDist != -1)
        dist = leftDist + 1, answer = max(answer, dist + rh);

    else if (rightDist != -1)
        dist = rightDist + 1, answer = max(answer, dist + lh);
    return max(lh, rh) + 1;
}
int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    ll distance = -1, target;
    cin >> target;
    burnTime(root, target, distance);
    cout << answer << endl;
}
