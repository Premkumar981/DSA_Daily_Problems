#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node*next;
	
};
struct Node*head,*temp;
int main(){
	int choice;
	cout<<"Enter choice(1,0): ";
	cin>>choice;
	while(choice){
		struct Node* newnode=new Node();
		cout<<"enter data: ";
		cin>>newnode->data;
		
		newnode->next=NULL;
		if(head==NULL){
			head=temp=newnode;
			
		}else{
			temp->next=newnode;
			temp=newnode;
		}
		cout<<"enter choice(1,0): ";
		cin>>choice;
		
	}
	int loc,i=1;
	temp=head;
	cout<<"enter location: ";
	cin>>loc;
	while(i<loc){
		temp=temp->next;
		i++;
	}
	struct Node*newnode=new Node();
	cout<<"enter data: ";
	cin>>newnode->data;
	newnode->next=temp->next;
	temp->next=newnode;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
		
	}
}
