#include<iostream>
using namespace std;
struct Node{
int data;
struct Node *next;
};
struct Node *head,*temp;
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
    int position, data;
    cout << endl;
    cout << "Enter the position to insert the new node: ";
    cin >> position;
    cout << "Enter the new data: ";
    cin >> data;
    Node* new_node = new Node();
    new_node->data = data;
    if (position == 1) {
        new_node->next = head;
        head = new_node;
    }
    else {
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return 0;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    cout << "Linked list after insertion: ";
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
return 0;
}

