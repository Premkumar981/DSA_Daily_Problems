#include <iostream>
using namespace std;
struct Node {
  int data;
  Node *next;
};
Node *head = NULL;
void insertAtBeginning(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}
void insertAtEnd(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}
void printList() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    insertAtBeginning(data);
  }
  cout << "Created Linked list: ";
  printList();
  int m;
  cin >> m;
  insertAtEnd(m);
  cout << "Final list: ";
  printList();
  return 0;
}
