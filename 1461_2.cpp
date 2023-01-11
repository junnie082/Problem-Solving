#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // abs for int, long int
using namespace std;

bool desc (int x, int y) {
	return x > y; 
}

int main()
{
	// 이거 치면 printf 만큼 빨라짐. 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; 
	cin >> N >> M; 

	vector<int> v; 
	v.push_back(0); 

	int num; 

	int min = 1000000;
	int max = 0; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		v.push_back(num);  
		if (num > max) max = num; 
		if (num < min) min = num; 
	}

	if (abs(min) > abs(max)) {
		sort(v.begin(), v.end(), desc); 
	} else {
		sort(v.begin(), v.end());
	}

	// for (int i = 0; i <= N; i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << endl; 
	int total = 0; 
	int index = 0; 

	while (1) {
		// cout << "index: " << index << " " << v[index] << endl; 
		total += abs(v[index] * 2);
		if (index+M < v.size()-1 && v[index]*v[index+M] <= 0) {
			while (v[index] != 0) {
				index++;
			}
			if ((v.size()-index-1)%M == 0) index += M;
			else if ((v.size()-index-1)%M+index < v.size()-1) index += (v.size()-index-1)%M;
			else {
				total += abs(v[v.size()-1]);
				break; 
			}	
		} else {
			index += M; 
		}

		if (index >= v.size() - 1) {
			total += abs(v[v.size()-1]); 
			break;
		}
	}

	cout << total; 
}