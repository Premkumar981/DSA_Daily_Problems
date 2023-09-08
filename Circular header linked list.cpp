#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class CircularLinkedList {
public:
  Node* head;

  CircularLinkedList() {
    head = NULL;
  }

  void insert(int data) {
    Node* new_node = new Node();
    new_node->data = data;

    if (head == NULL) {
      head = new_node;
      new_node->next = head;
    } else {
      Node* temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = new_node;
      new_node->next = head;
    }
  }

  void print() {
    Node* temp = head;
    if (head == NULL) {
      cout << "The list is empty." << endl;
      return;
    }

    cout << "The list is: ";
    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
  }
};

int main() {
  CircularLinkedList list;

  list.insert(1);
  list.insert(2);
  list.insert(3);

  list.print();

  return 0;
}

