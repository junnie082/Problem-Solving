#include <stdio.h>
#include <stdlib.h>

// 구조체.
typedef struct _conference {
	int start;
	int end; 
} conference;

conference sorted[100001];

//------------merge sort.
void merge(char sOre, conference list[], int start, int mid, int end) {
	int i, j, k; 
	i = start; 
	j = mid + 1; 
	k = start; 

	if (sOre == 'e') {
		while (i <= mid && j <= end) {
			if (list[i].end <= list[j].end) {
				sorted[k++] = list[i++]; 
			} else {
				sorted[k++] = list[j++]; 
			}
		}
	} else if (sOre == 's') {
		while (i <= mid && j <= end) {
			if (list[i].start <= list[j].start) {
				sorted[k++] = list[i++]; 
			} else {
				sorted[k++] = list[j++];
			}
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

void merge_sort(char sOre, conference list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; 
		merge_sort(sOre, list, left, mid);
		merge_sort(sOre,list, mid+1, right); 
		merge(sOre, list, left, mid, right); 
	}
}
//-------------------

int insertCon(conference list[], conference schedule[], int N) {
	
	schedule[0] = list[0]; 
	int k = 1, same = 0; 

	for (int i = 1; i < N; i++) {
		if (list[i].start < schedule[k-1].end) continue; 
		else schedule[k++] = list[i]; 
	}

	return k + same; 
}

int main()
{
	// 1. 구조체 배열 생성.
	conference *list = malloc(sizeof(conference) * 100001);

	int N; 
	int start, end; 
	scanf("%d", &N); 

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end); 
		list[i].start = start; 
		list[i].end = end; 
	}

	// 2. merge sort 이용.
	merge_sort('s',list, 0, N-1);
	merge_sort('e', list, 0, N-1); 

	// 3. 회의를 배정할 스케줄표 배열 생성
	conference *schedule = malloc(sizeof(conference) * N);

	// 4. 회의 넣기
	int k = insertCon(list, schedule, N);

 	printf("%d\n", k); 
 	// for (int i = 0; i < k; i++) {
 	// 	printf("%d %d\n", schedule[i].start, schedule[i].end);
 	// }

	free(list); free(schedule); 
}