#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n,m;
    cin>>n;
    vector<int> arr1(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>arr1[i];
    }
    
    cin>>m;
    vector<int>arr2(m);
    for (int i = 0; i < m; ++i)
    {
        cin>>arr2[i];
    }
    
    vector<int>merged(arr1.begin(), arr1.end());
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    
    int minIngredient =* min_element(merged.begin(),merged.end());
    cout<<minIngredient<<endl;
    return 0;
}
