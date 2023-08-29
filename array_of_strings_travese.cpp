// You are using GCC
#include <iostream>
#include <string>
using namespace std;
int main()
{
    const int MAX_SIZE = 100;
    int n;
    cin>>n;
    string strings[MAX_SIZE];
    for(int i = 0; i < n; ++i)
    {
        cin>> strings[i];
    }
    
    string searchString;
    cin>> searchString;
    int foundIndex = -1;
    for(int i = 0; i < n; ++i)
    {
        if (strings[i] == searchString)
        {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1)
    {
        cout<<foundIndex << endl;
    }else{
        cout<<"String not found!"<<endl;
    }
    return 0;
    
}
