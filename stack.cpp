#include<iostream>
using namespace std;
struct Node{
int data;
struct Node *next;
};
struct Node *top,*temp;
void push(){
struct Node *newnode=new Node();
cout<<"Enter data in stack:";
cin>>newnode->data;
if(top==NULL){
top=newnode;
temp=newnode;
}
else{
newnode->next=top;
temp=top=newnode;
}
}
void pop(){
if(top==NULL){
cout<<"Stack is underflow."<<endl;
}
else{
int item=temp->data;
top=top->next;
delete temp;
temp=top;
cout<<item<<"is deleted."<<endl;
}
}
void display(){
if(top==NULL){
cout<<"Stack is underflow."<<endl;
}
else{
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
}
cout<<endl;
}
void peek(){
if(top==NULL){
cout<<"Stack is underflow."<<endl;
}
else{
temp=top;
cout<<temp->data;
}
cout<<endl;
}
int main(){
int n;
cout<<"Enter 1 to start the program.";
cin>>n;
while(n){
int choice;
cout<<"1.PUSH"<<endl;
cout<<"2.POP"<<endl;
cout<<"3.DISPLAY"<<endl;
cout<<"4.PEEK"<<endl;
cout<<"Enter choice";
cin>>choice;
switch(choice){
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
peek();
break;
default:
cout<<"Invalid choice ."<<endl;
break;
}
}
}

