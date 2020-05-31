// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


 void makeLoop(Node* head, int x)
{
    if (x == 0)
        return;
    Node* curr = head;
    Node* last = head;

    int counter = 0;
    while (counter < x)
    {
        curr = curr->next;
        counter++;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}

int detectloop(Node* head)
{
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL)
    {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;

        if (hare == tortoise)
            return 1;
    }

    if (hare == tortoise)
        return 1;
    return 0;
}

 int length(Node* head, bool hasloop)
{
    int len = 0;
    if (hasloop == false)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    else
    {
        Node* hare = head->next;
        Node* tortoise = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;

            if (hare == tortoise)
                break;
        }

       
        int looplen = 0;
        while (hare->next!=tortoise)
        {
            hare = hare->next;
            looplen++;

        }
        
        looplen++;

        Node* begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise)
        {
            
            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;

        }

        

        return looplen + startlen;

        
    }
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

/*The function removes the loop from the linked list if present
You are required to complete this method*/

void removeTheLoop(Node *head)
{
    bool flag=false;
    
    if(head->next==head)
    {
        head->next= NULL;
    }
    if(head->next->next==head)
    {
        head->next->next= NULL;
    }
    
    Node *fast=head;
    Node *slow=head;
    
    while(slow->next!= NULL && fast->next!=NULL &&fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow==fast)
        { 
            flag=true;
            break;
        }
    }
    
    if(slow->next == NULL || fast->next == NULL)
    {
        flag = false;
    }
    
    if(flag == true)
    {
        slow = head;
        
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        return;
    }
}




// { Driver Code Starts.


int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *head=NULL, *tail=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
            if (head == NULL)
            {
                head = new Node(arr[i]);
                tail = head;
            }
            else
            {
                tail -> next = new Node(arr[i]);
                tail = tail -> next;
            }
        }

        int x;
        cin>>x;
        makeLoop(head,x);
        int lengthll=0;
        if(detectloop(head)==1)
        lengthll=length(head,true);
        else
        lengthll=length(head,false);
        
        removeTheLoop(head);
        
        if (detectloop(head) == 0 && lengthll == length(head, false))
        {
            cout<<1<<endl;
        }
        else
        cout<<0<<endl;
    }
    return 0;
}  // } Driver Code Ends