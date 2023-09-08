#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data = data;
			this->next = NULL;
		}

		~Node(){
			int value = this->data;
			if(this->next != NULL){
				delete next;
				this->next = NULL;
			}
			cout<<"Memory is free for node with with data "<<value<<endl;
		}
};

void InsertAtHead(Node* &head, int d){
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
    
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
    tail->next = NULL;
}

void insertMiddle(Node* &head, int position, int d){
    if(position == 1){
        InsertAtHead(head, d);
    }
    Node* temp = head;
    int i=0;
    while(i<position){
        temp = temp->next;
        i++;
    }
    Node* nodeInsert = new Node(d);
    nodeInsert->next = temp->next;
    temp->next = nodeInsert;
    
}

void print(Node* &head){
	Node* temp = head;
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

void deleteNode(int position, Node* &head){
	if(position==1){
		Node* temp = head;
		head = head->next;
		delete temp;
		
	}
	else{
		Node* curr = head;
		Node* prev = NULL;

		int i=1;
		while(i<=position){
			prev = curr;
			curr = curr->next;
			i++;
		}
		prev->next = curr->next;
		delete curr;
	}
}

int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
    Node* tail = node1;
    tail->next = NULL;
	// cout<<node1->data<<endl;
	// cout<<node1->next<<endl;
	InsertAtHead(head, 5);
    insertAtTail(tail, 4);
    insertMiddle(head,3,69);
	print(head);
	deleteNode(1, head);
	print(head);
	return 0;
}
