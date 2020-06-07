/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* 

Returns the lowest common ancestor in a Binary Tree

*/

Node* lca(Node* root, int n1, n2)
{
    if(root == NULL)
        return root;
        
    if(root->data == n1 || root->data == n2)
        return root;
        
    Node *left_lca = lca(root->left, n1, n2);
    Node *right_lca = lca(root->right, n1, n2);
    
    if(left_lca != NULL && right_lca != NULL)
        return root;
        
    return (left_lca == NULL) ? right_lca : left_lca;
}