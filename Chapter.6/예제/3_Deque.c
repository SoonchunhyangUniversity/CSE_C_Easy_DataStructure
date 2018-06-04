#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct DlistNode
{
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DlistNode;

typedef struct DequeType
{
	DlistNode *head;
	DlistNode *tail;
} DequeType;

/* 오류 처리 함수 */
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

/* 덱의 초기화 함수 */
void init(DequeType *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
}

/* 노드를 생성하는 함수 */
DlistNode *create_node(DlistNode *llink, element item, DlistNode *rlink)
{
	DlistNode *node = (DlistNode *)malloc(sizeof(DlistNode));

	if (node == NULL)
		error("메모리 할당 오류\n");

	node->llink = llink;
	node->rlink = rlink;
	node->data = item;

	return node;
}

/* 덱이 비어있는지 확인하는 함수 */
int is_empty(DequeType *dq)
{
	if (dq->head == NULL)
		return TRUE;

	else
		return FALSE;
}

/* 덱의 뒷부분에서 삽입하는 함수 */
void add_rear(DequeType *dq, element item)
{
	DlistNode *new_node = create_node(dq->tail, item, NULL);

	if (is_empty(dq))
		dq->head = new_node;

	else
		dq->tail->rlink = new_node;

	dq->tail = new_node;
}

/* 덱의 앞부분에서 삽입하는 함수 */
void add_front(DequeType *dq, element item)
{
	DlistNode *new_node = create_node(NULL, item, dq->head);

	if (is_empty(dq))
		dq->tail = new_node;

	else
		dq->head->llink = new_node;

	dq->head = new_node;
}

/* 덱의 앞부분에서 삭제하는 함수 */
element delete_front(DequeType *dq)
{
	element item;
	DlistNode *removed_node;

	if (is_empty(dq))
		error("덱이 비어있습니다.\n");

	else
	{
		removed_node = dq->head; // 삭제할 노드 저장
		item = removed_node->data; // 삭제될 데이터 저장
		dq->head = dq->head->rlink; // 덱의 헤드포인터 변경

		free(removed_node); // 노드의 메모리 할당 해제

		if (dq->head == NULL)
			dq->tail = NULL;

		else
			dq->head->llink = NULL;
	}

	return item;
}

/* 덱의 뒷부분에서 삭제하는 함수 */
element delete_rear(DequeType *dq)
{
	element item;
	DlistNode *removed_node;

	if (is_empty(dq))
		error("덱이 비어있습니다.\n");

	else
	{
		removed_node = dq->tail; // 삭제할 노드 저장
		item = removed_node->data; // 삭제될 데이터 저장
		dq->tail = dq->tail->llink; // 덱의 헤드포인터 변경

		free(removed_node); // 노드의 메모리 할당 해제

		if (dq->tail == NULL)
			dq->head = NULL;

		else
			dq->tail->rlink = NULL;
	}

	return item;
}

void display(DequeType *dq)
{
	DlistNode *p;

	printf("( ");

	for (p = dq->head; p != NULL; p = p->rlink)
		printf("%d ", p->data);

	printf(")\n");
}

int main()
{
	DequeType deque;

	init(&deque);

	add_front(&deque, 10);
	add_front(&deque, 20);
	add_rear(&deque, 30);

	display(&deque);

	delete_front(&deque);
	delete_rear(&deque);

	display(&deque);

	return 0;
}
