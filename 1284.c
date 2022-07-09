#include <stdio.h>
#include <string.h>

int width(char *str, int len){
	int sum = len + 1;

	for (int j=0; j<len; j++) {

		if (str[j] == '1') sum += 2;
		else if (str[j] == '0') sum += 4;
		else sum += 3;
	}

	return sum; 
}

int main()
{
	int i = 0;
	char str[5];

	while(1) {
		scanf("%s", str);
		if(*str == '0') break;
		printf("%d\n", width(str, strlen(str)));
	}
	return 0;
}