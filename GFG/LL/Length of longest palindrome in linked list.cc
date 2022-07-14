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

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */

int solve(Node* a, Node* b){
    int cnt = 0;
    while(a and b){
        if(a->data != b->data) break;
            cnt++;

        a = a->next;
        b = b->next;
    }
    return cnt;
}
int maxPalindrome(Node *head)
{
   int ans = 0;
   Node* curr = head;
   Node* prev = NULL; Node* next = NULL;
   while(curr){
       next = curr->next;
       curr->next = prev;
       
       ans = max(ans,2* solve(next,prev) + 1);  //odd len
       ans = max(ans,2* solve(next,curr));   //even len
       
       prev = curr;
       curr = next;
   }
   return ans;
}


Input
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2
