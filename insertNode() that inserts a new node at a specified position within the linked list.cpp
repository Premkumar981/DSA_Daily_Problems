#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertNode(string data, int position) {
        Node* newNode = new Node(data);

        if (position == 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentPosition = 1;

            while (currentPosition < position - 1 && current->next != nullptr) {
                current = current->next;
                currentPosition++;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void displayList() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;
        myList.insertNode(value, i + 1);
    }

    string dataToInsert;
    int positionToInsert;
    cin >> dataToInsert >> positionToInsert;

    cout << "Current Linked List:" << endl;
    myList.displayList();

    myList.insertNode(dataToInsert, positionToInsert);

    cout << "Updated Linked List:" << endl;
    myList.displayList();

    return 0;
}

