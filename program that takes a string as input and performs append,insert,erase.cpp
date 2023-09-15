#include <iostream>
#include <string>

using namespace std;

int main() {
    string initialString;
    string appendString;
    string insertString;
    int insertPosition;
    int erasePosition;
    int eraseCount;

    // Input
    getline(cin, initialString);
    getline(cin, appendString);
    getline(cin, insertString);
    cin >> insertPosition >> erasePosition >> eraseCount;

    // Append operation
    initialString += appendString;
    cout << "Modified string after append: " << initialString << endl;

    // Insert operation
    initialString.insert(insertPosition, insertString);
    cout << "Modified string after insert: " << initialString << endl;

    // Erase operation
    initialString.erase(erasePosition, eraseCount);
    cout << "Modified string after erase: " << initialString << endl;

    return 0;
}

