/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*

Return the height of node having data as 'key'

 */

int height(Node* root, int key, int h)
{
    if(root == NULL)
        return 0;
    
    if(root->data == key)
        return h;
        
    int downlevel = height(root->left, key, h+1);
    
    if(downlevel != 0)
        return downlevel;
        
    downlevel = height(root->right, key, h+1);
    
    return downlevel;
}