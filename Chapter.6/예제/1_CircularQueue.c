#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct
{
	element queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

/* 큐의 초기화 함수 */
void init(QueueType *q)
{
	q->front = q->rear = 0;
}

/* 큐가 비어있는지 확인하는 함수 */
int is_empty(QueueType *q)
{
	return  (q->front == q->rear);
}

/* 큐가 가득 차있는지 확인하는 함수 */
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

/* 큐의 삽입 함수 */
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.\n");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

/* 큐의 삭제 함수 */
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.\n");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->queue[q->front];
}

/* 큐의 피크 함수 */
element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.\n");

	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main()
{
	QueueType q;

	init(&q);

	printf("front = %d rear = %d\n", q.front, q.rear);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));

	printf("front = %d rear = %d\n", q.front, q.rear);

	return 0;
}
