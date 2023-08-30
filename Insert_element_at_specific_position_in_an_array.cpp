#include <iostream>
#include <vector>
using namespace std;
int main() {
int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
    cin>>arr[i];}
    int position, value;
    cin >> position >> value;
    if (position >= 1 && position <= size + 1) {
        cout << "Original array:";
        for (int i = 0; i < size; i++) {
            cout << " " << arr[i];}
            cout << endl;
            arr.insert(arr.begin() + position - 1, value);
            cout << "Updated array:";
        for (int i = 0; i < arr.size(); i++) {
            cout << " " << arr[i];}
        cout << endl;}
    else {
        cout << "Original array:";
        for (int i = 0; i < size; i++) {
            cout << " " << arr[i];}
        cout << endl;
        cout << "Invalid position!" << endl;}
    return 0;
}
