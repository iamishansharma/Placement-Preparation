/**

https://www.interviewbit.com/problems/reverse-link-list-ii/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) 
{
    ListNode *temp, *curr, *prev = NULL, *start, *end;
    temp = A;
    int i =1;
    
    while(temp != NULL)
    {
        if(m == 1)
        {
            start = temp;
            while(i<=n)
            {
                curr = temp->next;
                temp->next = prev;
                prev = temp;
                temp = curr;
                i++;
            }
            A = prev;
            start->next = curr;
            break;
        }
        else if(i == m-1)
        {
            start = temp;
            temp= temp->next;
            end = temp;
            i++;
            
            while(i<=n && temp!=NULL)
            {
                curr = temp->next;
                temp->next = prev;
                prev = temp;
                
                temp = curr;
                i++;
            }
            start->next = prev;
            
            if(curr!=NULL)
                end->next = curr;
        }
        else
        {
            i++;
            temp = temp->next;
        }
    }
    return A;
}
