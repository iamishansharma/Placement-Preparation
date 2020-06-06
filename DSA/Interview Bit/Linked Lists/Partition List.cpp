/**

https://www.interviewbit.com/problems/partition-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) 
{
    if(A==NULL || A->next==NULL) 
        return A;
        
    ListNode* head, *curr, *ptr, *temp;
    ptr = A; head = A;
    
    if(ptr->val >= B)
    {
        while(ptr->next && (ptr->next)->val >= B)
        {
            ptr = ptr->next;
        } 
        
        if(ptr->next==NULL)
            return A;
        
        temp = ptr->next;
        ptr->next = ptr->next->next;
        temp->next = head;
        head = temp;
    }
    curr = head; 
    ptr = curr;
    while(ptr->next != NULL)
    {
        if((ptr->next)->val < B && ptr->val >= B)
        {
            temp = ptr->next;
            ptr->next = (ptr->next)->next;
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next;
        }
        else
            ptr = ptr->next;
    }
    return head;
}
