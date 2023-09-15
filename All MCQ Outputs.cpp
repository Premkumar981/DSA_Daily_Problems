/*#include <iostream>
using namespace std;

int main(){
	int* wildPtr = nullptr;
	cout << *wildPtr;
	return 0;
}

#include<iostream>
using namespace std;
class Test{
	private:
		int x;
		public:
			Test() {x = 0;}
			void destroy() { delete this;
			}
			void print() { cout << "x = " << x; }
};
int main(){
	Test obj;
	obj.destroy();
	obj.print();
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	int x, *y;
	y=&x;
	x=10;
	cout<<++(*y);
}

#include<iostream>
using namespace std;
class Test
{
	private:
		int x;
		int y;
		public:
			Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
			static void fun1() { cout << "Inside fun1()"; }
			static void fun2() { cout << "Inside fun2()"; this->fun1(); }
			
};
int main()
{
	Test obj;
	obj.fun2();
	return 0;
}*/

#include<iostream>
class Data{
	public:
		int a;
		void print(){
			std::cout << "a is "<< a <<"\n";
		}
};
int main(){
	Data d, *dp;
	dp = &d;
	int Data::a*ptr=&Data::a;
	d.a*ptr=10;
	d.print();
	dp->a*ptr=20;
	dp->print();
}
