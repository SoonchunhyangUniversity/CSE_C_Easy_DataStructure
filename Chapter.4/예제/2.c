#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 // 배열의 최대 크기

typedef int element;

typedef struct
{
	element list[MAX_LIST_SIZE]; // 배열 정의
	int length; // 현재 배열에 저장된 자료들의 개수
 } ArrayListType;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 초기화
void init(ArrayListType *L)
{
	L->length = 0;
}

// 리스트가 비어 있으면 1을 반환 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}

// 리스트가 가득 차 있으면 1을 반환 그렇지 않으면 0을 반환
int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

// 리스트 출력
void display(ArrayListType *L)
{
	int i;
	for (i = 0; i < L->length; i++)
		printf("%d\n", L->list[i]);
}

// position : 삽입하고자 하는 위치, item : 삽입하고자 하는 자료
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
