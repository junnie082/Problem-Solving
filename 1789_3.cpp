#include <iostream>
using namespace std; 

int main() {
	unsigned long long int N;
	cin >> N; 

	unsigned long long int total = 0; 
	unsigned long long int remain;
	int index;
	for (int i = 1; i <= N; i++) {
		total += i; 
		remain = N - i; 
		if (remain <= total) {
			index = i; 
			break; 
		}
	}
 	
	cout << index; 
}