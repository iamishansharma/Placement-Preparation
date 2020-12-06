/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;

    if (temp == NULL)
        return NULL;

    while (temp != NULL && temp->next != NULL && temp->val == temp->next->val)
        temp = temp->next;

    if (temp == head)
    {
        head->next = deleteDuplicates(head->next);
        return head;
    }
    else
        return deleteDuplicates(temp->next);
}
