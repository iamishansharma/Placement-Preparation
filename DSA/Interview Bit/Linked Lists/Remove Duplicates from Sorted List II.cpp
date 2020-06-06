/**

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* root)
{
    if(!root||!root->next)
        return root;
        
    if(root->next->val != root->val)
    {
        root->next = deleteDuplicates(root->next);
        return root;
    }
    
    while(root->next && root->next->val == root->val)
        root = root->next;
    
    root = deleteDuplicates(root->next);
    
    return root;   
}
