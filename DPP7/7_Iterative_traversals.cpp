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
void inorderIterative(Node *root)
{
    stack<Node *> stack;
    Node *curr = root;
    while (!stack.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}
void preorderIterative(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        Node *curr = stack.top();
        stack.pop();
        cout << curr->data << " ";
        if (curr->right)
            stack.push(curr->right);
        if (curr->left)
            stack.push(curr->left);
    }
}

int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    inorderIterative(root);
    cout << endl;
    preorderIterative(root);
}
