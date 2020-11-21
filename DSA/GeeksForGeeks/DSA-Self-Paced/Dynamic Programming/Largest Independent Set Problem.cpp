// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to 
right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree
int LISS(struct Node *root);

/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    scanf("%d\n", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d\n", &n);
        struct Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << LISS(root) << endl;
    }
    return 0;
}
// } Driver Code Ends

// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree
int LISS(struct Node *root)
{
    if (root == NULL)
        return 0;

    int exclude = LISS(root->left) + LISS(root->right);

    int include = 1;

    if (root->left != NULL)
        include += LISS(root->left->left) + LISS(root->left->right);

    if (root->right != NULL)
        include += LISS(root->right->left) + LISS(root->right->right);

    return max(exclude, include);
}