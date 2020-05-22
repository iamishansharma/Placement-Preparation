// { Driver Code Starts
//Initial Template for C++

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
       head = reverseList(head);

       printList(head);

       cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Should reverse list and return new head.
Node* reverseList(Node *head)
{
    /*

    Using Stack -> 

    if(head == NULL)
        return head;
        
    stack<int> s;
    
    Node *temp = head;
    
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

    */

    // Without using stack -> 
     
    Node *current = head; 
    Node *prev = NULL, *next = NULL;
    
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next; 
    } 
    head = prev; 
    
    return head;
}