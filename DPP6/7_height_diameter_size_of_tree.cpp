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

ll calcHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

int calcDiameter(Node *root)
{
    if (root == NULL)
        return 0;
    ll lHeight = calcHeight(root->left);
    ll rHeight = calcHeight(root->right);
    ll currDiameter = lHeight + rHeight + 1;
    return max(currDiameter, (max(calcDiameter(root->left) * 1ll, calcDiameter(root->right) * 1ll)));
}

ll sizeoftree(Node *root)
{
    if (root == NULL)
        return 0;
    return sizeoftree(root->left) + sizeoftree(root->right) + 1;
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
    cout << "Height = " << calcHeight(root) << endl;
    cout << "Diameter = " << calcDiameter(root) << endl;
    cout << "Size of tree = " << sizeoftree(root) << endl;
    return 0;
}
