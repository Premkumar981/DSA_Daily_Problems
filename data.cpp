#include<iostream>
class MyClass
{
	public:
		int data=5;
		void printData(int d)
		{
			int data=d;
			std::cout<<data+" ";
			print();
		}
		void print(){
			std::cout<<data;
		}
};
int main()
{
	MyClass obj;
	obj.printData(10);
	return 0;
}
