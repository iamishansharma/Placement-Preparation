/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) 
{
    if(A == NULL) 
        return;

    TreeLinkNode *prevst = A;
    TreeLinkNode *node,*prev;

    while(prevst != NULL)
    {
        node = prevst;
        prevst = NULL;
    
        while(node != NULL)
        {
            if(node->left != NULL)
            {
                if(prevst == NULL)
                {
                    prev = node->left;
                    prevst = prev;
                }
                else
                { 
                    prev->next = node->left;
                    prev = prev->next;
                }
            }
        
            if(node->right != NULL)
            {
                if(prevst == NULL)
                {
                    prev = node->right;
                    prevst = prev;
                }
                else
                { 
                    prev->next = node->right;
                    prev = prev->next;
                }
            }
        
            node = node->next;
        }       
    }
}
