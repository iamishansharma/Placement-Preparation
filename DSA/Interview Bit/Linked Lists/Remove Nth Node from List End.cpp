/**

https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) 
{
    if(head == NULL)
        return head;
        
    if(head->next == NULL && n == 1)
        return NULL;
        
    /*

    WITH SIZE CALCULATED

    int size = 0;
    
    ListNode *temp = head;
    
    while(temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    if(n >= size)
    {
        head = head->next;
    }
    else
    {
        temp = head;
        for(int i=0; i<size-n-1; i++)
            temp = temp->next;
            
        temp->next = temp->next->next;
    }
    
    return head;*/

    // *********************************************************************************

    // WITHOUT CALCULATING SIZE. 

    /* 
    
    Logic: 
            Initiate two pointers A and B from head;

            Move only B 'n' steps forward.

            Now A from head, and B from above, start traversing till B reaches NULL;
            This make sures that A has travelled size - n + 1;

            Now we can delete A

    */

    ListNode *sec = head;
    ListNode *fir = head;

    for(int i=0; i<n; i++)
    {
        sec = sec->next;

        if(sec == NULL)
        {
            head = head->next;
            return head;
        }
    }

    while(sec->next != NULL)
    {
        fir = fir->next;
        sec = sec->next;
    }

    fir->next = fir->next->next;

    return head;
}
