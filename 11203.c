#include <stdio.h>
#include <math.h>

int main()
{
	int H, size, index = 1;
	char direction, opExist; 
	scanf("%d", &H); 

	size = pow(2, H + 1); 
	scanf("%c", &opExist);

	if (opExist == ' '){
		while (1) {
			scanf("%c", &direction);
			if (direction == '\n') break;

			if (direction == 'L') {
				index = index * 2; 
			} else if (direction == 'R') {
				index = index * 2 + 1; 
			} 
		}
	}
	printf("%d", size - index);
}

