#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_CHAR_PER_LINE 1000
#define MAX_NAME 256
#define TRUE 1
#define FALSE 0

typedef struct
{
	char a[MAX_CHAR_PER_LINE];
} element;

typedef struct ListNode
{
	element data;
	struct ListNode *link;
} ListNode;

typedef struct
{
	ListNode *head; // 헤드 포인터
	int length; // 노드의 개수
} LinkedListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void warning(char *message)
{
	fprintf(stderr, "%s\n", message);
}

int is_empty(LinkedListType *list)
{
	if (list->head == NULL)
		return TRUE;
	else
		return FALSE;
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

/* 리스트의 항목의 개수를 반환 */
int get_length(LinkedListType *list)
{
	return list->length;
}

/* 리스트 안에서 pos의 위치의 노드를 반환 */
ListNode *get_node_at(LinkedListType *list, int pos)
{
	int i;
	ListNode *tmp_node = list->head;

	if (pos < 0)
		return NULL;

	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;

	return tmp_node;
}

/* 주어진 위치에 데이터를 삽입 */
void add(LinkedListType *list, int position, element data)
{
	ListNode *p;

	if ((position >= 0) && (position <= list->length))
	{
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));

		if (node == NULL)
			error("메모리 할당에러");

		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

/* 리스트의 끝에 데이터를 삽입 */
void add_last(LinkedListType *list, element data)
{
	add(list, get_length(list), data);
}

/* 리스트의 처음에 데이터를 삽입 */
void add_first(LinkedListType *list, element data)
{
	add(list, 0, data);
}

/* 주어진 위치의 데이터를 삭제 */
void delete(LinkedListType *list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length))
	{
		ListNode *p = get_node_at(list, pos - 1);
		ListNode *removed = get_node_at(list, pos);

		remove_node(&(list->head), p, removed);
		list->length--;
	}
}

/* 주어진 위치에 해당하는 데이터 반환 */
element get_entry(LinkedListType *list, int pos)
{
	ListNode *p;

	if (pos >= list->length)
		error("위치 오류");

	p = get_node_at(list, pos);

	return p->data;
}

/* 모든 노드를 삭제 */
void clear(LinkedListType *list)
{
	int i;

	for (i = 0; i < list->length; i++)
		delete(list, i);
}

/* 버퍼의 내용을 출력 */
void display(LinkedListType *buffer)
{
	int i;
	ListNode *tmp_node;
	tmp_node = buffer->head;

	printf("\n├────────────────┤\n");
	for (i = 0; i < buffer->length; i++)
	{
		printf(" %s", tmp_node->data.a);
		tmp_node = tmp_node->link;
	}
	printf("├────────────────┤\n\n");
}

/* 리스트를 초기화 */
void init(LinkedListType *list)
{
	if (list == NULL)
		return;

	list->length = 0;
	list->head = NULL;
}

void help()
{
	printf("┌────────────────┐\n");
	printf("│ i : 입력       │\n");
	printf("│ d : 삭제       │\n");
	printf("│ r : 파일 읽기  │\n");
	printf("│ w : 파일 쓰기  │\n");
	printf("│ q : 종료       │\n");
	printf("└────────────────┘\n");
	printf("명령어를 입력하시오 : ");
}

/* 디스크 파일로부터 데이터를 읽기 */
void read_file(LinkedListType *buffer)
{
	char fname[MAX_NAME];
	FILE *fd;
	element p;

	if (!is_empty(buffer))
	{
		clear(buffer);
	}
	init(buffer);

	printf("파일 이름 : ");
	scanf("%s", fname);

	if ((fd = fopen(fname, "r")) == NULL)
	{
		warning("파일을 열 수 없습니다.");
		return;
	}

	while (fgets(p.a, MAX_CHAR_PER_LINE, fd))
	{
		add_last(buffer, p);
	}

	fclose(fd);
	display(buffer);
}

/* 버퍼에 있는 데이터를 디스크 파일에 쓰기 */
void write_file(LinkedListType *buffer)
{
	FILE *fd;
	char fname[MAX_NAME];
	element p;
	int i;

	printf("파일 이름 : ");
	scanf("%s", fname);

	if ((fd = fopen(fname, "w")) == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	for (i = 0; i < get_length(buffer); i++)
	{
		p = get_entry(buffer, i);
		fputs(p.a, fd);
	}

	fclose(fd);
	display(buffer);
}

/* 하나의 라인을 지우기 */
void delete_line(LinkedListType *buffer)
{
	int position;

	if (is_empty(buffer))
		printf("지울 라인이 없습니다.\n");
	else
	{
		printf("지우고 싶은 라인번호를 입력하세요 : ");
		scanf("%d", &position);
		delete(buffer, position);
	}
	display(buffer);
}


/* 하나의 라인을 삽입하기 */
void insert_line(LinkedListType *buffer)
{
	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;

	printf("입력 행 번호를 입력하세요 : ");
	scanf("%d", &position);

	printf("내용을 입력하세요 : ");
	getchar();
	fgets(line, MAX_CHAR_PER_LINE, stdin);

	strcpy(p.a, line);
	add(buffer, position, p);
	display(buffer);
}

void do_command(LinkedListType *buffer, char command)
{
	switch (command)
	{
	case 'd':
		delete_line(buffer);
		break;
	case 'i':
		insert_line(buffer);
		break;
	case 'r':
		read_file(buffer);
		break;
	case 'w':
		write_file(buffer);
		break;
	case 'q':
		break;
	}
}

int main()
{
	char command;
	LinkedListType buffer;

	init(&buffer);

	do
	{
		help();

		command = getchar();
		getchar();

		do_command(&buffer, command);
	} while (command != 'q');

	return 0;
}
