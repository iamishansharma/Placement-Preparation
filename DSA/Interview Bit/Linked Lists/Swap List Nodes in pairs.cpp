/**
 * 
 * https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) 
{
    if(A == NULL || A->next == NULL)
        return A;
    
    ListNode *curr = A,*n = NULL, *nn = NULL; 
    // n is next node to current 
    // nn is next to next node to current

    n = curr->next;
    nn = n->next;
    curr->next = swapPairs(nn);
    n->next = curr;
    
    return n;
}
