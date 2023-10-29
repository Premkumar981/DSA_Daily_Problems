#include <iostream>
using namespace std;

struct Bid {
    int bid_amount;
};

void swap(Bid& a, Bid& b) {
    Bid temp = a;
    a = b;
    b = temp;
}

void maxHeapify(Bid heap[], int i, int heapSize) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heapSize && heap[left].bid_amount > heap[largest].bid_amount) {
        largest = left;
    }

    if (right < heapSize && heap[right].bid_amount > heap[largest].bid_amount) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest, heapSize);
    }
}

void insertBid(Bid heap[], int& heapSize, Bid newBid) {
    // Insert the new bid at the end of the heap
    heap[heapSize] = newBid;
    int i = heapSize;
    heapSize++;

    // Fix the max-heap property if it's violated
    while (i > 0 && heap[(i - 1) / 2].bid_amount < heap[i].bid_amount) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(Bid heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].bid_amount << " ";
    }
    cout << endl;
}

int main() {
    int maxSize = 100;
    Bid binaryHeap[maxSize];
    int heapSize = 0;

    while (true) {
        Bid newBid;
        if (!(cin >> newBid.bid_amount)) {
            break;
        }
        if (heapSize < maxSize) {
            insertBid(binaryHeap, heapSize, newBid);
            printHeap(binaryHeap, heapSize);
        } else {
            cout << "Heap is full. Cannot insert more bids." << endl;
        }
    }

    return 0;
}

