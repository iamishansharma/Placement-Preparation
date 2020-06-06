/**

https://www.interviewbit.com/problems/sort-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
        
    ListNode* ans;
    
    if(A->val < B->val)
    {
        ans=A;
        A=A->next;
    }
    else
    {
        ans=B;
        B=B->next;
    }
    
    ListNode* a=ans;
    
    while(A != NULL && B != NULL)
    {
        if(A->val < B->val)
        {
            ans->next=A;
            A=A->next;
            ans=ans->next;
        }
        else
        {
            ans->next=B;
            B=B->next;
            ans=ans->next;
        }
    }
    
    if(B==NULL)
    {
        ans->next=A;
    }
    else
    {
        ans->next=B;
    }
    
    return a;
}
ListNode* Solution::sortList(ListNode* A) 
{
    if(A==NULL || A->next==NULL)
        return A;
        
    ListNode* slow=A;
    ListNode* temp=A;
    ListNode* fast=A;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    temp->next = NULL;
    ListNode* LS = sortList(A);
    ListNode* LR = sortList(slow);

    return mergeTwoLists(LS,LR);
}
