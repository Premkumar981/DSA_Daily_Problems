#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int frontIdx;
    int rearIdx;
    int count;

public:
    Queue() {
        frontIdx = -1;
        rearIdx = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int element) {
        if (isFull()) {
            return;
        }

        if (isEmpty()) {
            frontIdx = 0;
        }

        rearIdx = (rearIdx + 1) % MAX_SIZE;
        arr[rearIdx] = element;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        frontIdx = (frontIdx + 1) % MAX_SIZE;
        count--;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[frontIdx];
    }
};

int findQueueSum(Queue& q) {
    int sum = 0;

    while (!q.isEmpty()) {
        sum += q.front();
        q.dequeue();
    }

    return sum;
}

int main() {
    Queue q;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        q.enqueue(element);
    }

    if (q.isEmpty()) {
        cout << "Queue is empty." << endl;
        // cout << 0 << endl;
    } else {
        int sum = findQueueSum(q);
        cout << sum << endl;
    }

    return 0;
}

