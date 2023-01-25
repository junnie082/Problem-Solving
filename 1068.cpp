#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

int main()
{
	int N;
	cin >> N; 

	vector<int> tree[51];
	int roots[51] = {0};
	int input[51] = {0};

	int parent; 
	for (int i = 0; i < N; i++) {
		cin >> parent; 
		input[i] = parent; 
		if (parent == -1) continue; 
		else {
			tree[parent].push_back(i);
		} 
	}

	for (int i = 0; i < N; i++) {
		roots[i] = tree[i].size(); 
	}

	int del;
	cin >> del; 

	queue<int> que;
	que.push(del); 

	int index; 

	while (!que.empty()) {

		index = que.front();
		while (tree[index].size() > 0) {
			que.push(tree[index].back()); 
			tree[index].pop_back();
		}
		roots[index] = -1;
		que.pop(); 
	}


	if (input[del] >= 0) {
		roots[input[del]]--;

		for (int i = 0; i < N; i++) {
			if (roots[i] < 0) roots[i] = -1; 
		}

		int count = 0; 

		for (int i = 0; i < N; i++) {
			if (roots[i] == 0) count++; 
		}

			cout << count;
	} else {
		cout << 0; 
	}

	
}