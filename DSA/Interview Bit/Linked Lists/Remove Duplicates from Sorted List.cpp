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
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head;
    ListNode *nxt = temp->next;

    while (temp->next != NULL)
    {
        if (temp->val == nxt->val)
        {
            temp->next = nxt->next;
            nxt->next = NULL;
            free(nxt);
            nxt = temp->next;
        }
        else
        {
            temp = temp->next;
            nxt = temp->next;
        }
    }

    return head;
}
