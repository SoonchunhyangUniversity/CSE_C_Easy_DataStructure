#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 // 배열의 최대 크기

typedef int element;

typedef struct
{
	element list[MAX_LIST_SIZE]; // 배열 정의
	int length; // 현재 배열에 저장된 자료들의 개수
 } ArrayListType;

/* 오류 처리 함수 */
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

/* 리스트 초기화 */
void init(ArrayListType *L)
{
	L->length = 0;
}

/* 리스트가 비어 있으면 1을 반환 그렇지 않으면 0을 반환 */
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}

/* 리스트가 가득 차 있으면 1을 반환 그렇지 않으면 0을 반환 */
int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

/* 리스트 출력 */
void display(ArrayListType *L)
{
	int i;
	for (i = 0; i < L->length; i++)
		printf("%d\n", L->list[i]);
}

/* position : 삽입하고자 하는 위치, item : 삽입하고자 하는 자료 */
void add(ArrayListType *L, int position, element item)
{
	if (!is_full(L) && (position >= 0) && (position <= L->length))
	{
		int i;
		for (i = (L->length - 1); i >= position; i--)
			L->list[i + 1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}

/* position : 삭제하고자 하는 위치, 반환 값 : 삭제되는 자료 */
element delete(ArrayListType *L, int position)
{
	int i;
	element item;

	if (position < 0 || position >= L->length)
		error("위치 오류");

	item = L->list[position];

	for (i = position; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];

	L->length--;

	return item;
}

int main()
{
	ArrayListType list1;
	ArrayListType *plist;

	/*
		ArrayListType의 구조체를 정적으로 생성하고 이 구조체를 가리키는
		포인터를 함수의 매개 변수로 전달한다.
	*/
	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);

	/*
		ArrayListType의 구조체를 동적으로 생성하고 이 구조체를 가리키는
		포인터를 함수의 매개 변수로 전달한다.
	*/
	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	free(plist);

	return 0;
}
