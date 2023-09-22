#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string studentName) : name(studentName), next(nullptr) {}
};

class StudentRoster {
private:
    Node* head;
    int size;

public:
    StudentRoster() : head(nullptr), size(0) {}

    void insertNode(string studentName, int position) {
        Node* newNode = new Node(studentName);

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

        size++;
    }

    void displayRoster() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    StudentRoster roster;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string studentName;
        cin >> studentName;
        roster.insertNode(studentName, i + 1);
    }

    string newStudentName;
    int position;
    cin >> newStudentName >> position;

    cout << "Current Linked List:" << endl;
    roster.displayRoster();

    roster.insertNode(newStudentName, position);

    cout << "Updated Linked List:" << endl;
    roster.displayRoster();

    return 0;
}

