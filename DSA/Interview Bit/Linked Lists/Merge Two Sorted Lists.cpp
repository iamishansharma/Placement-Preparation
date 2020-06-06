/**

https://www.interviewbit.com/problems/merge-two-sorted-lists/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(!A) 
        return B;
        
    if(!B) 
        return A;
        
    if(A->val > B->val)
        return mergeTwoLists(B, A);
        
    A->next = mergeTwoLists(A->next, B);
    
    return A;
}
