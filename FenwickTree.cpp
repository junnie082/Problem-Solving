#include <iostream>
https://min-ingful.tistory.com/26
using namespace std;

int arr[9] = {0, 0, 2, 1, 5, 7, 8, 13, 4};
int tree[9];
int n = 8;

void add(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k & -k;
    }
}

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

int main()
{
    for (int i = 1; i < 9; i++) {
        add(i, arr[i]);
    }
    for (int i = 1; i < 9; i++) {
        cout << tree[i] << " ";
    }
    cout << "3부터 7까지의 구간합: " << sum(7) - sum(3-1) << endl;
    cout << endl;
}