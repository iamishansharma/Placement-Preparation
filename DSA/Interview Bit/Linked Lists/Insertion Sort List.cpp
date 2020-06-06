/**

https://www.interviewbit.com/problems/insertion-sort-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* a) 
{
    ListNode *dummy = new ListNode(INT_MIN);
    
    if(!a || !a->next) 
        return a;
    
    ListNode *temp = a;
    
    while(temp)
    {
        ListNode *b = dummy;
        while(b->next && b->next->val < temp->val)
        {
            b = b->next;
        }
        ListNode *x = temp;
        temp = temp->next;
        x->next = b->next;
        b->next = x;
    }
    return dummy->next;
}
