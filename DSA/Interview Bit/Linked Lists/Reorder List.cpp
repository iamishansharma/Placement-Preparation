/**

https://www.interviewbit.com/problems/reorder-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* a) 
{
    if(a == NULL || a->next == NULL || a->next->next == NULL)
        return a;
    
    ListNode* ptr1 = a, *ptr2 = a;
    
    while(ptr2->next != NULL && ptr2->next->next != NULL) 
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    
    ptr1=ptr1->next; 
    ptr2=NULL;
    
    while(ptr1 != NULL) 
    {
       ListNode* temp = ptr1->next;
       ptr1->next = ptr2;
       ptr2 = ptr1;
       ptr1 = temp;
    }

    ptr1=a;
    while(ptr2!=NULL) 
    {
        ListNode* temp1 = ptr1->next, *temp2 = ptr2->next;
        ptr1->next = ptr2;
        ptr2->next = temp1;
        ptr1=temp1;
        ptr2=temp2;
    }
    
    if(ptr1!=NULL)
        ptr1->next = NULL; 

    return a;
}
