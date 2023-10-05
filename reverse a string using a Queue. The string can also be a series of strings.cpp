#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    
    queue<char> q;
    
    // Add characters to the queue
    for (char c : str) {
        q.push(c);
    }
    
    // Remove characters from the front of the queue and add to the string
    string reversed_str = "";
    while (!q.empty()) {
        reversed_str = q.front() + reversed_str;
        q.pop();
    }
    
    cout << "Reversed string: " << reversed_str << endl;
    return 0;
}

