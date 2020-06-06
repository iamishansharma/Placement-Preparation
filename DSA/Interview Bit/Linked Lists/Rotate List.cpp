/**

https://www.interviewbit.com/problems/rotate-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    ListNode* temp_end = A;
    
    int length = 0;
    
    while(temp_end->next != NULL)
    {
        temp_end = temp_end->next;
        length++;
    }
    length++;
    
    B = B % length;
    
    for(int i = 0; i<(length - B); i++)
    {
        temp_end->next = A;
        A = A->next;
        temp_end = temp_end->next;
        temp_end->next = NULL;
    }
    return A;
}
