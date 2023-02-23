#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	
	int N;
	cin >> N; 
	stack<int> nums; 

	int num;
	int counts[1000001] = {0};  

	// nums, counts
	int maxIndexOfPri = 0; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		nums.push(num); 
		counts[num]++;
		if (counts[num] > maxIndexOfPri)
			maxIndexOfPri = counts[num]; 
	}

	// priorityNum 동적 할당. 
	int *priorityNum = new int[maxIndexOfPri+1]; 
	int *priority = new int[maxIndexOfPri+1]; 
	for (int i = 0; i <= maxIndexOfPri; i++) {
		priorityNum[i] = 0; 
		priorityNum[i] = 0; 
	}
	int priIndex; 
	int val; 

	vector<int> res; 

	int count = 1;
	while (!nums.empty()) {

		val = nums.top(); 
		priIndex = counts[val];
		priorityNum[priIndex] = val; 
		priority[priIndex] = count++; 

		//cout << " priIndex: " << priIndex << endl; 
		priIndex++; 

		// 다음이 0 이지만, 숫자가 나올 때까지 찾아야 할 때.
		int index = priIndex; 
		for (int i = priIndex; i <= maxIndexOfPri; i++) {
			if (priority[index] < priority[i]) {
				index = i; 
			}
		}

		if (priIndex > maxIndexOfPri || priority[index] == 0) {
			res.push_back(-1); 
		} else {
			res.push_back(priorityNum[index]); 
		}

		nums.pop();
	}

	for (int i = N-1; i >= 0; i--) {
		cout << res[i] << " "; 
	}

	delete[] priorityNum; 

	return 0; 
}