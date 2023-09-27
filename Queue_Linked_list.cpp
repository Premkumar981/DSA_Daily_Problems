#include<iostream>
using namespace std;
struct Node{
int data;
Node *next;
};
Node *temp,*front=NULL,*rear=NULL;
void enqueue(){
struct Node *newnode=new Node();
cout<<"Enter data:";
cin>>newnode->data;
newnode->next=NULL;
if(front==NULL & rear==NULL){
front=rear=newnode;
}
else{
rear->next=newnode;
rear=newnode;
}
}
void dequeue(){
if(front==NULL){
cout<<"Queue is Underflow."<<endl;
}else{
temp=front;
front=front->next;
delete temp;
temp=front;
}
}
void display(){
if(front==NULL){
cout<<"Queue is Underflow."<<endl;
}
else{
temp=front;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<endl;
}
}
void peek(){
if(front==NULL){
cout<<"Queue is Underflow."<<endl;
}
else{
cout<<rear->data;
}
cout<<endl;
}
int main(){
int n;
cout<<"Enter 1 to start program:";
cin>>n;
while(n){
int choice;
cout<<"1.Enqueue"<<endl;
cout<<"2.Dequeue"<<endl;
cout<<"3.Display"<<endl;
cout<<"4.Peek"<<endl;
cout<<"5.Exit"<<endl;
cout<<"Enter choice:";
cin>>choice;
switch(choice){
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
peek();
break;
case 5:
exit (0);
}
}
return 0;
}
2 way linked list
stack
queue 
priority queue using ll
Tower of hinoi
binary search tree
-insertion
-searching
travesing
-preorder
-postorder
-inorder
polish notation - mcqs
