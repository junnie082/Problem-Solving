#include <stdio.h>
#include <stdlib.h>

typedef struct _stack
{
	int *data;
	int stack_size;
}stack;

void initializeStack(stack *s, int stackMaxSize)
{
	s->data = (int*)calloc(stackMaxSize, sizeof(int));
	s->stack_size = 0;
}

void pushStack(stack *s, int v) {
	s->data[s->stack_size++] = v;
}

int popStack(stack *s)
{
	int v;
	v = s->data[(s->stack_size) - 1];
	s->data[s->stack_size--] = 0; 
	return v;
}


int main() 
{
	char p[50];
	int a, b, c,flag = 0, t;
	stack s, op, opand;

	//initializeStack(&s, 5);

	scanf("%d %d %d", &a, &b, &c);
	getchar();
	scanf("%[^\n]", p);

	printf("%c", p[1]);

}

