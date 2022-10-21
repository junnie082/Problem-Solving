#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// 정적 배열을 이용하자.
	int T, n, len, isFromFirst, index;
	scanf("%d", &T);
	char c, p[100001];


	while (T--){
		isFromFirst = 1;

		scanf("%s", p);
		scanf("%d", &n); 

		char **str = malloc(sizeof(char) * n);

		for (int i = 0 ; i < n; i++) {
			str[i] = malloc(sizeof(char) * 4); 
		}

		len = strlen(p); 
		for (int i = 0 ; i < len; i++) {
			if (p[i] == 'R') isFromFirst = !isFromFirst;
			else if (p[i] == 'D') {
				if (isFromFirst) {
					
				}
			}
		}

		len = 0; 

		while(1){
			scanf("%c", &c);
			if ( c == '[') continue;
			else if (c == ',') { 
				index++;
				len = 0; 
			} else if (c == ']') {
				break;
			} 
			else {
				//strcat(str[index], &c); 
				str[index][len] = c;
				len++;
			}
		}
			
		for (int i = 0 ; i < n ; i++) {
			free(str[i]);
		}
		free(str); 
	}

}