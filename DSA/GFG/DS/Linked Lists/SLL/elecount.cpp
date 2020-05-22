// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int count(struct node* head, int search_for);
/* Link list node */
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;

void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new node(value);
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= new node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

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

    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     value=count(head, k);
     printf("%d\n",value);
     }
     return(0);
}// } Driver Code Ends


/*
  Return the no. of times search_for value is there in a linked list.
  The input list will have at least one element  

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

// iterative 
/*int count(struct node* head, int search_for)
{
    int count = 0;
    struct node *temp = head;
    
    while(temp != NULL)
    {
        if(temp->data == search_for)
            count++;
        
        temp = temp->next;
    }
    
    return count;
}*/

// recursive
int countrec(struct node* head, int search_for, int freq)
{
    if(head == NULL)
        return freq;
        
    if(head->data == search_for)
        freq += 1;
        
    return countrec(head->next, search_for, freq);
}
int count(struct node* head, int search_for)
{
    return countrec(head, search_for, 0);
}