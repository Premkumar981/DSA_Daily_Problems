#include<iostream>
using namespace std;
struct Node{
int data;
struct Node *next;
};
struct Node *head,*temp,*temp1;
int main(){
int choice;
cout<<"Enter your choice(0/1):";
cin>>choice;
while(choice){
struct Node *newnode=new Node();
cout<<"Enter the data:";
cin>>newnode->data;
newnode->next=NULL;
if(head==NULL){
head=newnode;
temp=newnode;
}
else{
temp->next=newnode;
temp=newnode;
}
cout<<"Enter the choice (0/1):";
cin>>choice;
}
temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
temp=head;
int position,i=1;
cout<<endl;
cout<<"Enter the position of element to be deleted:";
cin>>position;
while(i<position-1){
temp=temp->next;
i++;
}
temp1=temp->next;
temp->next=temp1->next;
cout << "Linked list after insertion: ";
    temp = head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
return 0;
}

