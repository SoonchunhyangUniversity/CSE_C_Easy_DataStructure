#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode
{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

/*
	phead : 리스트의 헤드 포인터의 포인터
	p : 선행 노트
	new_node : 삽입될 노드
 */
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if (*phead == NULL) // 공백 리스트인 경우
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) // p가 NULL이면 첫 번째 노드로 삽입
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

/*
	phead : 헤드 포인터의 포인터
	p : 삭제될 노드의 선행 노트
	removed : 삭제될 노드
*/
void remove_node(ListNode **phead, ListNode *p, ListNode *remove)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = remove->link;

	free(remove);
}

void display(ListNode *head)
{
	ListNode *p = head;

	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

void display_recur(ListNode *head)
{
	ListNode * p = head;

	if (p != NULL)
	{
		printf("%d->", p->data);

		display_recur(p->link);
	}
}

ListNode *search(ListNode *head, int x)
{
	ListNode *p;
	p = head;

	while (p != NULL)
	{
		if (p->data == x)
			return p; // 탐색 성공

		p = p->link;
	}

	return p; // 탐색 실패일 경우 NULL 반환
}

/*
	head1 = (a1, a2, ..., an) head2 = (b1, b2, ..., bn)을
	(a1, ..., an, b1, ..., bn)으로 변환
*/
ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;

	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else
	{
		p = head1;

		while (p->link != NULL)
		{
			p = p->link;
			p->link = head2;

			return head1;
		}
	}
}

/* (e1, e2, ... en)을 (en, en-1, ..., e1)로 변환 */
ListNode *reverse(ListNode * head)
{
	// 순회 포인터로 p, q, r을 사용
	ListNode *p, *q, *r;
	p = head; // p는 아직 처리되지 않은 노드
	q = NULL; // q는 역순으로 만들 노드

	while (p != NULL)
	{
		r = q; // r은 역순으로 된 노드
		q = p; // r은 q, q는 p를 차례로 따라간다.
		p = p->link;
		q->link = r; // q의 링크 방향을 바꾼다.
	}

	return q; // q는 역순으로 된 리스트의 헤드포인터
}

/* 노드를 동적으로 생성하는 프로그램 */
ListNode *create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));

	if (new_node == NULL)
		error("메모리 할당 에러");

	new_node->data = data;
	new_node->link = link;

	return (new_node);
}

int main()
{
	ListNode *list1 = NULL, *list2 = NULL;
	ListNode *p;

	// list1 = 30->20->10
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	// list1 = 20->10
	remove_node(&list1, NULL, list1);
	display(list1);

	// list2 = 80->70->60
	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	// list1 = list1 + list2
	list1 = concat(list1, list2);
	display(list1);

	// list1을 역순으로
	list1 = reverse(list1);
	display(list1);

	// list1에서 20 탐색
	p = search(list1, 20);
	printf("탐색성공 : %d\n", p->data);

	return 0;
}
