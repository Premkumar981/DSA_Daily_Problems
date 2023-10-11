
#include<iostream>
using namespace std;
void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
	
}
int partition(int arr[], int low, int high){    //low = start, high = end
	int pivot = arr[low];
	int start = low + 1;
	int end = high;
	
	while(start <= end){
		while(arr[start] <= pivot){
			start++;
		}while(arr[end] >= pivot && end >= start){
			end--;
		}
		if(end < start){
			break;
		}
		swap(&arr[start], &arr[end]);
	}
	swap(&arr[low], &arr[end]);
	return end;
}
void quickSort(int arr[], int low, int high){
	if(low< high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main(){
	int size, i;
	cout<<"enter size of array: ";
	cin >>size;
	
	int arr[size];
	
	for(i = 0;i < size; i++){
		cin >> arr[i];
	}
	cout << "Original Array: "<<endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	quickSort(arr, 0, size - 1);
	
	cout << "Sorted Array: "<<endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] <<" ";
	}
}
