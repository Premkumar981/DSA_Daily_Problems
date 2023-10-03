#include <iostream>
#include <string>

const int MAX_SIZE = 100;

struct Book {
    std::string title;
    int quantity;
    int restockPriority;
};

struct PriorityQueue {
    Book arr[MAX_SIZE];
    int size;

    PriorityQueue() : size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    void push(const Book& book) {
        if (size == MAX_SIZE) {
            std::cout << "Queue is full. Cannot add more books.\n";
            return;
        }

        int index = size;
        arr[size++] = book;

        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index].restockPriority < arr[parent].restockPriority) { // Lower values indicate higher priority
                std::swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "No books in the inventory.\n";
            return;
        }

        arr[0] = arr[--size];

        int index = 0;
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && arr[leftChild].restockPriority < arr[smallest].restockPriority) { // Lower values indicate higher priority
                smallest = leftChild;
            }

            if (rightChild < size && arr[rightChild].restockPriority < arr[smallest].restockPriority) { // Lower values indicate higher priority
                smallest = rightChild;
            }

            if (smallest != index) {
                std::swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

    Book top() {
        if (isEmpty()) {
            std::cout << "No books in the inventory.\n";
            return {"", 0, 0};
        }
        return arr[0];
    }
};

int main() {
    PriorityQueue inventory;

    int choice;
    do {
        
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the previous input

        switch (choice) {
            case 1: {
                std::string title;
                int quantity, priority;
                //std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                //std::cout << "Enter quantity: ";
                std::cin >> quantity;
                //std::cout << "Enter restock priority (1-5): ";
                std::cin >> priority;
                if (priority < 1) priority = 1;
                if (priority > 5) priority = 5;
                inventory.push({title, quantity, priority});
                std::cout << "Book added to the inventory.\n";
                break;
            }
            case 2:
                if (!inventory.isEmpty()) {
                    std::cout << "Restocked book: " << inventory.top().title << "\n";
                    inventory.pop();
                } else {
                    std::cout << "No books in the inventory.\n";
                }
                break;
            case 3:
                if (!inventory.isEmpty()) {
                    std::cout << "Next book to restock: " << inventory.top().title << "\n";
                } else {
                    std::cout << "No books in the inventory.\n";
                }
                break;
            case 4:
                std::cout << "Exiting the application.";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

