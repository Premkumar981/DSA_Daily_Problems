// You are using GCC
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void insertTask(int heap[], int& heapSize, int newTask) {
    // Insert the new task at the end of the heap
    heap[heapSize] = newTask;
    int i = heapSize;
    heapSize++;
    // Fix the max-heap property if it's violated
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void printHeap(int heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main() {
    int maxHeapSize = 100;
    int maxHeap[maxHeapSize];
    int heapSize = 0;
    while (true) {
    	int newTask;
    	if (!(cin >> newtask)){
    		break;
		}
		
		if (heapSize < maxHeapSize){
			insertTask(maxHeap, heapSize, newTask);
		}
		else{
			cout<<"Heap is full, cannot insert more tasks."<<endl;
			break;
		}
	}
	
	printHeap(maxHeap, heapSize);
	
	return 0;
}
