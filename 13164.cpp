#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

bool desc(int a, int b) {
	return a > b; 
}

int main()
{
	int N, K; 
	cin >> N >> K;

	vector<int> nums; 
	vector<int> gaps; 

	int num; 
	for (int i = 0; i < N; i++) {
		cin >> num; 
		nums.push_back(num); 
	}

	for (int i = 0; i < N-1; i++) {
		gaps.push_back(nums[i+1] - nums[i]); 
	}

	sort(gaps.begin(), gaps.end(), desc);
	int gap = 0; 

	for (int i = 0; i < K-1; i++) {
		gap += gaps[i]; 
	}

	int result; 
	result = (nums[N-1] - nums[0]) - gap; 
	cout << result; 

}