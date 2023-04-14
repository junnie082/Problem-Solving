#include <iostream>
#include <vector>
using namespace std; 

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	// (주유소 가격, 거리)
	vector<pair<int, int> > gas;

	unsigned long long int cost, distance;

	// distance
	for (int i = 0; i < N-1; i++) {
		cin >> distance;
		gas.push_back(make_pair(0, distance));
	}

	// cost
	for (int i = 0; i < N; i++) {
		cin >> cost;
		if (i == N-1) gas.push_back(make_pair(cost, 0));
		else gas[i].first = cost;
	}

	cost = gas[0].first;
	distance = gas[0].second; 

	// count 를 gas[0].first * gas[0].second 로 초기화 하면 에러.
	// count 를 cost * distance 로 초기화 하면 맞았습니다. 왜?
	//unsigned long long int count = (gas[0].first) * (gas[0].second); 
	unsigned long long int count = cost * distance;

	for (int i = 1; i < gas.size(); i++) {
		if (gas[i].first < cost) {
			cost = gas[i].first;
		}
		distance = gas[i].second; 
		count += cost * distance;
	}

	cout << count; 
}