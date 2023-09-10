#include <iostream>

using namespace std;

struct Node {
int data;
Node* next;
};

Node* createNode(int data) {
Node* newNode = new Node;
if (newNode == NULL) {
//cout << "Memory allocation failed!";
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}

Node* reverseKNodes(Node* head, int k) {
Node* current = head;
Node* next = NULL;
Node* prev = NULL;
int count = 0;
// Reverse the first k nodes of the linked list
while (current != NULL && count < k) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
}

// If there are more nodes in the linked list, recursively reverse the remaining nodes
if (next != NULL)
    head->next = reverseKNodes(next, k);

return prev;
}

void displayList(Node* head) {
if (head == NULL) {
cout << "Empty List!";
return;
}
Node* temp = head;
while (temp != NULL) {
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}

void deleteList(Node* head) {
Node* temp;
while (head != NULL) {
temp = head;
head = head->next;
delete temp;
}
}

int main() {
int n, k;
cin >> n;
Node* head = NULL;
Node* tail = NULL;
for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

cin >> k;

cout << "Original Linked List: ";
displayList(head);

head = reverseKNodes(head, k);

cout << "Modified Linked List: ";
displayList(head);

deleteList(head);

return 0;
}
