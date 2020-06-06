/**

https://www.interviewbit.com/problems/palindrome-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A)
{
    ListNode* ptr=A;
    
    int n=0;
    
    while(ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }
    
    ptr=A;
    int idx=n/2;
    
    while(idx--)
    {
        ptr=ptr->next;
    }
    
    ListNode *cur=ptr;
    ListNode *next=NULL, *prev=NULL;
    
    while(cur != NULL)
    {
        next=cur->next;
        cur->next=prev;
        
        if(next==NULL)
            break;
            
        prev=cur;
        cur=next;
    }
    
    int ok=1;
    idx=n/2;
    
    while(idx--)
    {
        if(A->val != cur->val)
            return 0;
            
        A = A->next;
        cur = cur->next;
    }
    return 1;
}
