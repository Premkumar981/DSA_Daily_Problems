#include <iostream>
#include <string>

// Function to merge two arrays and return the merged array size
int mergeArrays(std::string fiction[], int fictionSize, std::string nonFiction[], int nonFictionSize, std::string merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays
    while (i < fictionSize && j < nonFictionSize) {
        merged[k++] = fiction[i++];
        merged[k++] = nonFiction[j++];
    }

    // Copy the remaining elements from the fiction array
    while (i < fictionSize) {
        merged[k++] = fiction[i++];
    }

    // Copy the remaining elements from the non-fiction array
    while (j < nonFictionSize) {
        merged[k++] = nonFiction[j++];
    }

    // Return the size of the merged array
    return k;
}

int main() {
    const int MAX_SIZE = 100; // Maximum size of the arrays

    int fictionSize, nonFictionSize;

    std::cin >> fictionSize;

    std::cin.ignore(); // Clear the newline character from the input buffer

    std::string fiction[MAX_SIZE];

    for (int i = 0; i < fictionSize; i++) {
        std::getline(std::cin, fiction[i]);
    }

    std::cin >> nonFictionSize;

    std::cin.ignore(); // Clear the newline character from the input buffer

    std::string nonFiction[MAX_SIZE];

    for (int i = 0; i < nonFictionSize; i++) {
        std::getline(std::cin, nonFiction[i]);
    }

    // Calculate the maximum possible size of the merged array
    int maxSize = fictionSize + nonFictionSize;
    std::string merged[MAX_SIZE];

    // Merge the arrays and get the size of the merged array
    int mergedSize = mergeArrays(fiction, fictionSize, nonFiction, nonFictionSize, merged);

    // Display the merged array in the given input order
    std::cout << "Catalog: " << std::endl;
    for (int i = 0; i < fictionSize; i++) {
        std::cout << fiction[i] << std::endl;
    }
    for (int i = 0; i < nonFictionSize; i++) {
        std::cout << nonFiction[i] << std::endl;
    }

    return 0;
}
