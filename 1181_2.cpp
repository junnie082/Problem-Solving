#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int N; 
	cin >> N; 

	vector< pair<int, string> > strList; 
	string str; 

	for (int i = 0; i < N; i++) {
		cin >> str; 
		strList.push_back(make_pair(str.length(),str)); 
	}

	sort(strList.begin(), strList.end());

	// 왜 strList 의 int 기준이 아닌, string 을 기준으로 erase 가 되었는가? 
	strList.erase(unique(strList.begin(), strList.end()), strList.end()); 

	for (int i = 0; i < strList.size(); i++) {
		cout << strList[i].second << endl; 
	}

	return 0;
}