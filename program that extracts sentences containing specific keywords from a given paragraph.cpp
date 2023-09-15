#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> extract(const string& paragraph, const string& keyword) {
    vector<string> extractedSentences;
    size_t startPos = 0;

    while (true) {
        size_t foundPos = paragraph.find('.', startPos);
        if (foundPos == string::npos) {
            break;
        }

        string sentence = paragraph.substr(startPos, foundPos - startPos + 1);
        if (sentence.find(keyword) != string::npos) {
            extractedSentences.push_back(sentence);
        }

        startPos = foundPos + 1;
    }

    return extractedSentences;
}

int main() {
    string paragraph, keyword;
    getline(cin, paragraph);
    getline(cin, keyword);

    vector<string> extractedSentences = extract(paragraph, keyword);

    if (extractedSentences.empty()) {
        cout << "0" << endl;
    } else {
        cout << extractedSentences.size() << endl;
        for (const string& sentence : extractedSentences) {
            cout << sentence << " ";
        }
        cout << endl;
    }

    return 0;
}

