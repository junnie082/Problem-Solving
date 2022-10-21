#include <stdio.h>
int list[1000001];
int sorted[1000001]; 

void merge(int start, int mid, int end) {
	int i, j, k;
	i = start; 
	j = mid + 1; 
	k = start;

	while (i <= mid && j <= end) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		} else {
			sorted[k++] = list[j++];
		}
	}

	while (i <= mid) {
		sorted[k++] = list[i++];
	}

	while (j <= end) {
		sorted[k++] = list[j++];
	}

	for (i = start; i <= end; i++) {
		list[i] = sorted[i]; 
	}

}

void merge_sort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; 
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);  
	}
}

int main()
{
	int N, num; 
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		list[i] = num; 
	}

	merge_sort(0, N-1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", list[i]); 
	}
 
 	return 0; 
}