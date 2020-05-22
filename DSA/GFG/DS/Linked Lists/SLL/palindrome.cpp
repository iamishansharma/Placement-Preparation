// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
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
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    stack<int> s; // Push every element (head to tail) in stack.
    
    Node *temp = head;
    
    while(temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;

    while(!s.empty()) // Now compare every element in stack 
                      //  with head to tail (because stack will reverse the list) 
    {
        if(s.top() != temp->data)
            return false;
        else
        {
            s.pop();
            temp = temp->next;
        }
    }
    return true;
}

