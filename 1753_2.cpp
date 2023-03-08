#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;  // 이게 오름차순임. 
	}
};

int main() 
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 

	unsigned long long updated[20001] = {0};

	// updated 에 최댓값인 20,000을 넘는 값으로 초기화. 
	int V, E, K;
	cin >> V >> E >> K;

	// 계속 [틀렸습니다] 가 뜨는 이유는... 혹시
	// 처음에 초기화된 updated 값이 너무 작기 때문?
	for (int i = 1; i <= V; i++) {
		//updated[i] = 2000000;
		updated[i] = INT_MAX;
	}

	// updated[K], 즉 K 번째 정점은 시작점이므로 0 으로 업데이트. 
	updated[K] = 0;
	int u, v, w;

	// nodes, Linked List 와 비슷한 구조를 벡터 배열로 표현.
	// #1. 
	//priority_queue< pair<int, int>, vector< pair<int, int> >, cmp > nodes[20001];
	// #2.
	vector< pair<int, int> > nodes[20001];

	// u 번째 정점에 연결된 v 정점과 두 정점을 연결하는 간선의 가중치 w. 
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(v, w)); 
	}

	// 정점 v 와 가중치 w 를 쌍으로 묶어 담은 큐. 
	//queue< pair<int, int> > que;
	priority_queue< pair<int, int>, vector< pair<int, int> >, cmp > que; 
		
	// 첫 번째 정점인 K와 가중치 0.
	que.push(make_pair(K, 0));
	int topV;

	while (!que.empty()) {
		
		topV = que.top().first;
		//cout << "topV: " << topV << "second: " << que.top().second << "size: " << que.size() << endl; 
		//que.pop(); 
		//cout << "first: " << que.top().first << "second: " << que.top().second << endl; 
		// # 1. que에 값을 먼저 넣어버리면, 우선순위 큐의 장점을 살릴 수가 없음. 
		while (!nodes[topV].empty()) {
			// cout << "in first: " << nodes[topV].top().first << "in second: " << nodes[topV].top().second << endl; 
			//que.push(make_pair(nodes[topV].back().first, 
			//	nodes[topV].back().second));

			updated[nodes[topV].back().first] =
				min(updated[nodes[topV].back().first], 
				updated[topV] + nodes[topV].back().second);

			// 이거였다.......
			// 간선의 값, 즉 가중치를 기준으로 우선 순위 큐를 구성하는 것이 아니라,
			// 처음 정점에서부터 현재 정점까지의 최단 거리를 우선순위 큐 페어의 두 번째 값으로 넣어야 했던 거다... 
			que.push(make_pair(nodes[topV].back().first, updated[nodes[topV].back().first])); 

			nodes[topV].pop_back(); 
		}
		que.pop(); 
	}

	for (int i = 1; i <= V; i++) {
		if (updated[i] == INT_MAX) cout << "INF" << '\n'; 
		else cout << updated[i] << '\n'; 
	}

}