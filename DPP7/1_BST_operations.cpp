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

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (key < root->data)
        return searchInBST(root->left, key);
    return searchInBST(root->right, key);
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteInBST(root->left, key);
    else if (key > root->data)
        root->right = deleteInBST(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }

        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val > root->data)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

int32_t main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    if (searchInBST(root, 5) == NULL)
        cout << "Key does not exist" << endl;
    else
        cout << "Key exists" << endl;
    inorder(root);
    cout << endl;
    deleteInBST(root, 5);
    inorder(root);
    cout << endl;
    Node *tree = insertIntoBST(root, 5);
    inorder(root);
    return 0;
}
