#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int n, m, v, a, b, i, j=0, k=1, t=1, flag = 0;
	scanf("%d %d %d", &n, &m, &v);
	int *arr = calloc(2*m, sizeof(int));
	int *result = calloc(n, sizeof(int));
    
	i = m;

	while(i--) {
		scanf("%d %d", &a, &b);
		arr[j++] = a;
		arr[j++] = b;
	}

	result[0] = v;

	for (int j = 1; j <= m; j++){
		//이 부분 수정할 것.

		for (int i = 0; i < 2*m; i++) {

			if (v == arr[i]) {
				if (i%2 == 0) {
					
					for (int q = 0; q < k; q++) {
						if (result[q]==arr[i+1]) flag = 1;
					}	
					if (flag) {
						flag = 0;
						continue;
					}
					result[k++] = arr[i+1];

				} else if (i%2==1) {

					for (int q = 0; q < k; q++) {
						if (result[q]==arr[i-1]) flag = 1;
					}
					if (flag) {
						flag = 0;
						continue;
					}
					result[k++] = arr[i-1];
				}
 			}
		}
		v = result[t++];
	}

	for (int i = 0; i<n; i++) {
		printf("%d", result[i]);
		if (i!=n-1) printf(" ");
	}

	free(arr);
	free(result);
}