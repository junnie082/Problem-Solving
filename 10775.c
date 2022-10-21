#include <stdio.h>
#include <stdlib.h>
// 첫 번째 방법. 이중 for 문 사용.
int main()
{
	//AVL Tree 쓰면 될 것 같은데...
	int G, P, val, result = 0, flag = 0, start, sum = 0;
	scanf("%d", &G);
	scanf("%d", &P);
	int *plane = (int *)calloc(P+1, sizeof(int));
	int *gate = (int *)calloc(G+1, sizeof(int));

	for (int i = 1; i <= P; i++) {
		scanf("%d", &val); 
		plane[i] = val; 
	}

	for (int i = 1; i <= P; i++) {
		if ( G < sum ) break;
		
		if (G >= plane[i]) {
			sum++;
		}
		else if (G < plane[i]) {
			
		}

	}

	printf("%d", result);
}