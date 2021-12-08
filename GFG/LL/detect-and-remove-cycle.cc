#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl


// Floyd Cycle Detection Algorithm
// Hare and Tortoise Algorithm


// To find the meeting point we need to move fast by two step and slow by small steps.
// Next to find the point of cycle formation , move both the pointer by one step.

class Node{
    public:
        int data;
        Node* next;
            Node(int val){
            data = val;
            next = NULL;
    }
};
// l is the circumference of the circle
// Distance moved by slow pointer = m + l*i + n
// Distance moved by fast pointer = m + l*j + n 

// Distance moved by fast pointer = 2*Distance moved by slow pointer
// m + l*j + n = 2(m + l*i + n)

// m = l*(j-2*i) - n
// (j-2*i) = is an integer value  
// m = left piece of circle


void insertAtTail(Node* &head ,int val){
	Node* n = new Node(val);

	if(head==NULL){
		    head = n;
		return;
		}

	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void insertAtHead(Node* &head,int val){
	Node* n = new Node(val);
	n->next=head;
	head = n;
}

void makeCycle(Node* &head,int pos){
    Node* temp = head;
    Node* startNode;

    int count=1;
    while(temp->next!=NULL){

        if(count==pos){
            startNode=temp;
        }
        temp = temp->next;
        count++;
        
    }
    temp->next = startNode;
}

bool detectCycle(Node* &head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
            return true;
    }
    return false;
}

void removeLoopGfg(Node* head){
  if(!head or !head->next) return;
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow) break;  //if cycle found
    }
    if(slow!=fast) return; //no cycle
           
    if(slow==head){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }else{
        fast=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = NULL;
    }
}
 void removeLoop(Node* head){
        if(!head or !head->next) return;
        Node *slow=head,*fast=head,*prev=0;
    
        while(fast and fast->next){
           prev=slow , slow=slow->next , fast=fast->next->next;       
        
           if(slow==fast) break;   //if cycle found
        }
        if(slow!=fast) return;    //no cycle --> just return

        fast=head;
        while(slow!=fast){
            prev= slow , slow=slow->next , fast=fast->next;
        }

        prev->next=0;
        
    }
void display(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
    
	cout<<"NULL"<<endl; 
}

int main()
{
    Node* head=NULL;
    insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);

    display(head);
    makeCycle(head,1);debug(detectCycle(head));
    // removeLoopGfg(head);debug(detectCycle(head));
    removeLoop(head);debug(detectCycle(head));
    display(head);
    
    return 0;
}

