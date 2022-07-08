#include <stdio.h>

int chess(char arr[][8]){
	int horse = 0;

	for (int i = 0; i < 8; i++) {
		for (int j=0; j<8; j++) {
			if ( (i+j) % 2 == 0 && arr[i][j] == 'F') horse++;
		}
	}

	return horse;
}

int main()
{
	// 문자열의 마지막에는 NULL이 들어가야 하니, 문자열의 크기보다 크게 공간을 설정.
	char arr[8][8], s[9];

	for (int i=0; i<8; i++) {
		scanf("%s", s);
		for (int j=0; j<8; j++){
			arr[i][j] = s[j];
		}
	}

	printf("%d", chess(arr));
}