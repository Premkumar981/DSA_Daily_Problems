#include<iostream>
using namespace std;
int main(){
	int arr[]={9,4,5,63,2,8,7,5,6,1};
	int count=sizeof(arr)/sizeof(arr[0]);
	int i,j,temp;
	
	cout<<"Before sorting:";
	for(i=0;i<count;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	cout<<"After sorting:";
	for(i=0;i<count;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		
		arr[j+1]=temp;
	}
	for (i=0;i<count;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
