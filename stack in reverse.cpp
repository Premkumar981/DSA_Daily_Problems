#include<iostream>
using namespace std;
int main(){
	int i,n;
	char a[10];
	cout<<"Enter the string: ";
	cin>>a;
	n = sizeof(a)/sizeof(a[0]);
	cout<<"String in reverse: ";
	for(i=n;i>=0;i--){
		cout<<a[i];
	}
	
	return 0;
}
