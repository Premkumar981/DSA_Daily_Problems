#include <iostream>
using namespace std;
#define MAX 100

class Deque {
	int arr[MAX];
	int front;
	int rear;
	int size;

public:
	Deque(int size)
	{
		front = -1;
		rear = 0;
		this->size = size;
	}

	// Operations on Deque:
	void insertfront(int key);
	void insertrear(int key);
	void deletefront();
	void deleterear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
};


bool Deque::isFull()
{
	return ((front == 0 && rear == size - 1)
			|| front == rear + 1);
}


bool Deque::isEmpty() { 
    return (front == -1); 
}

void Deque::insertfront(int key)
{

	if (isFull()) {
		return;
	}

	if (front == -1) {
		front = 0;
		rear = 0;
	}

	else if (front == 0)
		front = size - 1;

	else 
		front = front - 1;

	arr[front] = key;
}

void Deque ::deletefront()
{
	if (isEmpty()) {
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else
		if (front == size - 1)
		front = 0;
	else 
		front = front + 1;
}

int Deque::getFront()
{
	if (isEmpty()) {
		return -1;
	}
	return arr[front];
}

int main()
{
	int len;
	cin>>len;
	Deque dq(len);
	int val;
    for(int i=0;i<len;i++)
    {
        cin>>val;
	    dq.insertfront(val);
    }

	cout << "The front element is " << dq.getFront() <<"."<< endl;

    int del;
    cin>>del;
    for(int i=0;i<del;i++)
    {
        dq.deletefront();
    }

	cout << "After deletion, the front element becomes " << dq.getFront() <<"."<< endl;
	return 0;
}
