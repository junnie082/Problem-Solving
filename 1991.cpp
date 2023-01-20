#include <iostream>
#include <stack>
#include <queue>
using namespace std; 

typedef struct _Node {
	char left; 
	char right; 
} Node; 

void PreOrder(Node *nodes) {
	int visited[27] = {0};

	// 방문을 이미 한 공간에는 1을, 그렇지 않은 공간에는 0을 넣을 것임. 
	stack<char> s;
	s.push('A'); 

	int a = 3;
	char curr; 
	while (!s.empty()) {
		curr  = s.top(); 

		if (visited[s.top()-'A'] == 0) {
			cout << s.top();
			visited[s.top()-'A'] = 1; 
		}

		if (nodes[s.top()-'A'].left != '.') {
			s.push(nodes[s.top()-'A'].left); 
			nodes[curr-'A'].left = '.';
		} else if (nodes[s.top()-'A'].right != '.') {
			s.push(nodes[s.top()-'A'].right);
			nodes[curr-'A'].right = '.'; 
		} else {
			s.pop(); 
		}
	}
}

void InOrder(Node *nodes) {
	stack<char> s;
	s.push('A');

	int visited[27] = {0};

	char curr;  
	while (!s.empty()) {
		curr = s.top(); 
		if (nodes[s.top()-'A'].left != '.') {
			s.push(nodes[s.top()-'A'].left); 
			nodes[curr-'A'].left = '.'; 
		} else if (nodes[s.top()-'A'].left == '.' && nodes[s.top()-'A'].right != '.') {
			cout << s.top(); 
			visited[s.top()-'A'] = 1;
			s.push(nodes[s.top()-'A'].right); 
			nodes[curr-'A'].right = '.'; 
		} else {
			if (visited[s.top()-'A'] == 0) cout << s.top();
			visited[s.top()-'A'] = 1;
			s.pop(); 
		}
	}
}

void PostOrder(Node *nodes) {
	stack<char> s;
	s.push('A'); 
	// cout << s.top(); 
	int index; 

	while (!s.empty()) {

		index = s.top()-'A';

		if (nodes[index].left == '.' && nodes[index].right == '.') {
			cout << s.top(); 
			s.pop();
		} 

		if (nodes[index].right != '.') {
			s.push(nodes[index].right); 
			nodes[index].right = '.';
		}

		if (nodes[index].left != '.') {
			s.push(nodes[index].left);
			nodes[index].left = '.';
		}
	
	}
}

int main()
{	
	Node nodesPre[26];
	Node nodesIn[26];
	Node nodesPost[26];

	int N; 
	cin >> N; 
 	
 	for (int i = 0; i < 26; i++) {
 		nodesPre[i].left = '.'; nodesIn[i].left = '.'; nodesPost[i].left = '.';
 		nodesPre[i].right = '.'; nodesIn[i].right = '.'; nodesPost[i].right = '.';
 	}
	char parent, left, right;
	for (int i = 0; i < N; i++) {
		cin >> parent >> left >> right; 
		nodesPre[parent-'A'].left = left; 
		nodesIn[parent-'A'].left = left; 
		nodesPost[parent-'A'].left = left;

		nodesPre[parent-'A'].right = right; 
		nodesIn[parent-'A'].right = right; 
		nodesPost[parent-'A'].right = right;
	}	

	// cout << nodes['B'-'A'].left << endl; 
	PreOrder(nodesPre); 
	cout << endl; 
	InOrder(nodesIn); 
	cout << endl;
	PostOrder(nodesPost); 
}