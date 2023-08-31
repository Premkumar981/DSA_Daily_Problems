#include <iostream>

int* mergeSortedArrays(const int* arr1, const int* arr2, int size1, int size2, int& mergedSize) {
    int* mergedArr = new int[size1 + size2];
    int i = 0;  // Pointer for arr1
    int j = 0;  // Pointer for arr2
    int k = 0;  // Pointer for mergedArr
    
    // Merge the arrays until one of them is fully traversed
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        } else {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements from arr1, if any
    while (i < size1) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements from arr2, if any
    while (j < size2) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
    
    mergedSize = k;
    return mergedArr;
}

int main() {
    int size1, size2;
    std::cin >> size1;
    int* arr1 = new int[size1];
    for (int i = 0; i < size1; i++) {
        std::cin >> arr1[i];
    }
    std::cin >> size2;
    int* arr2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        std::cin >> arr2[i];
    }
    
    int mergedSize = 0;
    int* mergedArr = mergeSortedArrays(arr1, arr2, size1, size2, mergedSize);
    for (int i = 0; i < mergedSize; i++) {
        std::cout << mergedArr[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;
    
    return 0;
}
