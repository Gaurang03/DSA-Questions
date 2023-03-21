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

ll Ceil(Node *root, ll input)
{
    if (root == NULL)
        return -1;
    if (root->data == input)
        return root->data;
    if (root->data < input)
        return Ceil(root->right, input);
    ll ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->data;
}

ll Floor(Node *root, ll input)
{
    if (root == NULL)
        return -1;
    if (root->data == input)
        return root->data;
    if (root->data > input)
        return Floor(root->left, input);
    else
    {
        ll floor = Floor(root->right, input);
        return (floor <= input && floor != -1) ? floor : root->data;
    }
}

int32_t main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    cout << "Enter the value to find the ceil for" << endl;
    ll value;
    cin >> value;
    cout << Ceil(root, value) << endl;
    cout << "Enter the value to find the floor for" << endl;
    cin >> value;
    cout << Floor(root, value) << endl;
}
