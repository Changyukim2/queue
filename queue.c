#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Queuetype;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(Queuetype* q) {
	q->rear = q->front = 0;
	

}

int is_full(Queuetype* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(Queuetype *q) {
	
	return (q->front == q->rear);
}

void queue_print(Queuetype *q) {
	printf("QUEUE( front=%d  rear=%d ) =", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);

	}
	printf("\n");
}

void enqueue(Queuetype* q, element item) {
	if (is_full(q)) 
		error("큐가 포화상태입니다");
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	
}

element dequeue(Queuetype* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(Queuetype* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];

}

int main(void) {

	Queuetype queue;
	int element;
	int num;
	


	init_queue(&queue);
	
	while (1) {
		printf("*** MENU ****\n");
		printf("1.input data and enqueue\n");
		printf("2.dequeue and print data\n");
		printf("3. print queue\n");
		printf("4. exit\n");
		printf("select number: ");
		scanf("%d", &num);
		switch (num) {
		case 1:
			printf("input data:");
			scanf("%d", &element);
			enqueue(&queue, element);
			printf("enqueue: %d\n", element);
			break;
		case 2:
			
			printf("dequeue : %d\n", dequeue(&queue));
			break;
		case 3:
			queue_print(&queue);
			break;
		case 4:
			printf("exit the program\n");
			exit(1);
			

		}
	}
	return 0;
}