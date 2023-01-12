#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N; 

	vector<int> v; 
	int w;
	for (int i = 0; i < N; i++) {
		cin >> w; 
		v.push_back(w); 
	}

	sort(v.begin(), v.end()); 

	int max = 0; 
	for (int i = 0; i < N; i++) {
		if (max < v[i] * (N-i)) {
			max = v[i] * (N-i); 
		}
	}

	cout << max; 
}