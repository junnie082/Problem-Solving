#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	return a.second > b.second;
}

int main()
{
	int N; 
	cin >> N; 
	vector<pair<int, int> > v;

	int d, w; 
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		v.push_back(pair<int, int>(d, w));
	}

	sort(v.begin(), v.end(), compare); 

	// for (int i = 0; i < N; i++) {
	// 	cout << v[i].first << " " << v[i].second << endl;
	// }
	int greedy[1001] = {0}; 
	int index, limit = 0; 
	for (int i = 0; i < N; i++) {
		d = v[i].first;
		w = v[i].second; 
		index = d; 
		if (limit <= d) limit = d; 
		for (int k = d; k >= 0; k--) {
			if (greedy[k] == 0) {
				index = k; break;
			}
			if (greedy[index] < greedy[k]) {
				index = k; 
			}
		}
		if (greedy[index] < w)
			greedy[index] = w;
	}

	int result = 0; 
	for (int i = 1; i <= limit; i++) {
		result += greedy[i]; 
	}

	cout << result;  

}