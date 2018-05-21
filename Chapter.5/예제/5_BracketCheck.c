#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct
{
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

/* 스택 초기화 함수 */
void init(StackType *s)
{
	s->top = -1;
}

/* 공백 상태 검출 함수 */
int is_empty(StackType *s)
{
	return (s->top == -1);
}

/* 포화 상태 검출 함수 */
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

/* 삽입 함수 */
void push(StackType *s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}

	else
		s->stack[++(s->top)] = item;
}

/* 삭제 함수 */
element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}

	else
		return s->stack[(s->top)--];
}

/* 피크 함수 */
element peek(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}

	else
		return s->stack[s->top];
}

/* 괄호 검사 함수 */
int check_matching(char *in)
{
	StackType *s;
	char ch, open_ch;
	int i, n = strlen(in);

	init(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i]; // 다음 문자

		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			break;

		case ')':
		case ']':
		case '}':
			if (is_empty(&s))
				return FALSE;

			else
			{
				open_ch = pop(&s);

				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}'))
					return FALSE;
			}
			break;

		default:
			break;
		}
	}

	/* 스택에 남아있으면 오류 */
	if (!is_empty(&s))
		return FALSE;

	return TRUE;
}

int main()
{
	if (check_matching("{ A[(i + 1)] = 0; }") == TRUE)
		printf("괄호 검사 성공\n");

	else
		printf("괄호 검사 실패\n");

	return 0;
}
