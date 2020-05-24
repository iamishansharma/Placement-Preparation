// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;
     
     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;
         
         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }
        
        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);
    
     }
     
     return(0);

}

// } Driver Code Ends


/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
#include <stack>

struct node *reverse (struct node *head, int k)
{ 
    if(head == NULL)
        return head;
        
    stack<int> s;
    
    int count = 0;
    
    struct node *temp = head;
    
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    
    if(k > count)
    {
        temp = head;
        
        while(temp != NULL)
        {
            s.push(temp->data);
            temp = temp->next;
        }
        
        temp = head;
        
        while(!s.empty())
        {
            temp->data = s.top();
            s.pop();
            temp = temp->next;
        }
    }
    else
    {
        struct node *start = head;
        
        while(count > 0)
        {
            if(k <= count)
            {
                temp = start;
                
                for(int i=1; i<=k; i++)
                {
                    s.push(temp->data);
                    temp = temp->next;
                }
                
                temp = start;
                
                for(int i=1; i<=k; i++)
                {
                    temp->data = s.top();
                    s.pop();
                    temp = temp->next;
                }
                
                start = temp;
                count -= k;
            }
            else
            {
                temp = start;
                
                for(int i=1; i<=count; i++)
                {
                    s.push(temp->data);
                    temp = temp->next;
                }
                
                temp = start;
                
                for(int i=1; i<=count; i++)
                {
                    temp->data = s.top();
                    s.pop();
                    temp = temp->next;
                }
                
                start = temp;
                count -= count;
            }
        }
    }
    return head;
}
