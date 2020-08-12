/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverse(ListNode **head)
{
    ListNode *prev = NULL;
    ListNode *curr = *head;
    ListNode *next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int compare(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->val != temp2->val)
            return 0;
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    if(temp1 == NULL && temp2 == NULL)
        return 1;
    else
        return 0;
}

int Solution::lPalin(ListNode* head) 
{
    if(head == NULL || head->next == NULL)
        return 1;
    
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = head;
    ListNode *midnode = NULL;
    
    int ans = 0;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    if(fast != NULL) 
    {
        // this becomes true when list has 
        // odd elements hence skipping the mid node
        
        midnode = slow;
        slow = slow->next;
    }
    
    ListNode *secondhalf = slow;
    prev->next = NULL;
    
    reverse(&secondhalf); // reverse the second half of the list
    
    ans = compare(head, secondhalf);
    
    reverse(&secondhalf); // reverse the second half list again to make it normal
    
    if(midnode != NULL) // odd list
    {
        prev->next = midnode;
        midnode->next = secondhalf;
    }
    else
        prev->next = secondhalf;
        
    return ans;
}
