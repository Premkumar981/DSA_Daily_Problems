#include <iostream>
using namespace std;

const long long mod = 10000000010LL;

long long power (long long a, long long b) { 
	if (b == 0) {
		return 1;
	}
	long long temp = power (a, b / 2); 
	long long result = (temp * temp) % mod;

	if (b % 2 == 1) { 
		result (result * a) % mod;
	}
	return result;
}

int main() { 
	int T; 
	cin >> T; 
	while (T--) {
		long long a, b;
		cin >> a >> b;
		long long result = power (a, b); 
		cout << result << " "<<endl;

	} 
	cout << endl;
	return 0;
}
