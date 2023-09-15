#include <iostream>
#include <sstream>
#include <string>

double calculateAverageWordLength(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::string word;
    int totalLength = 0;
    int wordCount = 0;

    while (iss >> word) {
        totalLength += word.length();
        wordCount++;
    }

    return static_cast<double>(totalLength) / wordCount;
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    double averageLength = calculateAverageWordLength(input);
    std::cout.precision(3);
    std::cout << std::fixed << averageLength << std::endl;

    return 0;
}

