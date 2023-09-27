#include<iostream>
using namespace std;
#define N 5
int front=-1;
int rear=-1;
int queue[N];
void enqueue(){
	int x;
	if(rear==N-1){
		cout<<"Queue is overflow.";
	}else if(front==-1 && rear==-1){
		front=rear=0;
		cout<<"Enter data:";
		cin>>x;
		queue[rear]=x;
	}
	else{
		cout<<"Enter data:";
		cin>>x;
		rear=rear+1;
		queue[rear]=x;
	}
}
void dequeue(){
	if(front==-1){
		cout<<"Queue is underflow.";
	}else{
		front++;
	}
}
void display(){
	if(front==-1){
		cout<<"Queue is underflow.";
	}else{
		int i;
		for(i=front;i<=rear;i++){
			cout<<queue[i]<<" ";
		}
	}
	cout<<endl;
}
void peek(){
	if(front==-1){
		cout<<"Queue is underflow.";
	}else{
		cout<<queue[rear];
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
