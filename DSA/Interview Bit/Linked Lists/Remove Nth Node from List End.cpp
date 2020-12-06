/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{
    ListNode *temp = A;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (count == 1)
        return NULL;

    if (B >= count)
    {
        A = A->next;
        return A;
    }

    int d = count - B - 1;

    int i = 0;
    temp = A;
    ListNode *temp2 = A;

    while (i < d)
    {
        temp = temp->next;
        i++;
    }

    temp->next = (temp->next)->next;

    return A;
}
