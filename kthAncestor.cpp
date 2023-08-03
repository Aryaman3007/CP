#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *solve(Node *root, int node, int &k)
{
    if (root == NULL)
        return root;
    if (root->data == node)
        return root;

    Node *left = solve(root->left, node, k);
    Node *right = solve(root->right, node, k);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }

    if (right != NULL && left == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    //Tc-> O(N) 
    //SC-> O(N):recursion stack space
    Node *ans = solve(root, node, k);
    if (ans == NULL || ans->data == node)
        return -1;
    return ans->data;
}
