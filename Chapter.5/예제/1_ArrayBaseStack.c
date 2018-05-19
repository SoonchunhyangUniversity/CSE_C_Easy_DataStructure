#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

/* 공백 상태 검출 함수 */
int is_empty()
{
	return (top == -1);
}

/* 포화 상태 검출 함수 */
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

/* 삽입 함수 */
void push(element item)
{
	if (is_full())
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}

	else
		stack[++top] = item;
}

/* 삭제 함수 */
element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}

	else
		return stack[top--];
}

/* 피크 함수 */
element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}

	else
		return stack[top];
}

int main()
{
	push(1);
	push(2);
	push(3);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", is_empty());

	return 0;
}
