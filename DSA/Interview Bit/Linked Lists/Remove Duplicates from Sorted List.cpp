/**

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) 
{
    if(head == NULL)
        return head;
        
    ListNode *temp = head;
    
    while(temp->next != NULL)
    {
        if(temp->val == temp->next->val)
        {
            ListNode *del = temp->next;
            temp->next = temp->next->next;
            delete(del);
        }
        else
            temp = temp->next;
    }
    return head;
}
