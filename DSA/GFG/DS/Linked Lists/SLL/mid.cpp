// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

    printf("%d\n", getMiddle(head));
    }
    return 0;
}
// } Driver Code Ends


/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/

// Single Pointer 
/*int getMiddle(Node *head)
{
    if(head == NULL)
        return -1;
        
    int n=0;
    
    Node *temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        n++;
    }
    
    int mid = 0;
    
    if(n % 2 == 0)
        mid = n/2 + 1;
    else
        mid = (n+1)/2;
        
    temp = head;
    for(int i=1; i<mid; i++)
    {
        temp = temp->next;
    }
    
    return temp->data;
}*/

// Double Pointer
int getMiddle(Node *head)
{
    if(head == NULL)
        return -1;
        
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}
