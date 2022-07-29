#include <stdio.h>
#include <stdlib.h>

// if (denominator == NULL) break;
		// *denominator++ = i;
		//denominator++;
// -> 이것이 메모리 해제 오류를 불러 일으키는 이유는, 포인터 자체를 ++ 해버리면 
// 메모리를 해제하려고 할 때는 배열의 맨 첫 부분을 가리키는 것이 아니게 되어버리기 때문일 것이다. 

void calFunc(int *nominator, int *denominator, int M, int N)
{	
	for (int k = 1; k <= N; k++){
		for (int i = 0; i < k; i++) {
			if (nominator[i] == 1) continue;
			for (int j = 0; j < N; j++) {
				if (denominator[j] == 1) continue;
				if (nominator[i] % denominator[j] == 0) {
					nominator[i] /= denominator[j];
					denominator[j] = 1;
				}
				if (denominator[j] % nominator[i] == 0) {
					denominator[j] /= nominator[i];
					nominator[i] = 1;
				}
			}
		}
	}
}

int main()
{
	int N, M, T, n, d, flag;


	scanf("%d", &T);

	while (1) {

		n = 1;
		d = 1;

		if (!T) break;
		scanf("%d %d", &N, &M);

		int *nominator = (int *)malloc(sizeof(int)* N);
		int *denominator = (int *)malloc(sizeof(int) * N);

		// 분모
		flag = 0;
		for (int i = M; i > M-N; i--) nominator[flag++] = i;
		
		flag = 0;
		// 분자
		for (int i = 1; i <= N; i++) denominator[flag++] = i;
		

		calFunc(nominator, denominator, M, N);

		// 분모 계산
		for (int i = 0; i < N; i++) n *= nominator[i];
		// 분자 계산
		for (int i = 0; i < N; i++) d *= denominator[i];

		printf("%d\n",n/d);

		free(nominator);
		free(denominator);

		T--;
	}
}