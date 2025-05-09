// ť ����
#include <stdlib.h>
#include <stdio.h>

#define QueueError (-1);

typedef struct {
	int* data; //�迭������
	int front; // ������ ���� ��ġ
	int rear; // ������ ���� ��ġ
	int capacity; // �ִ�ũ��
} Queue;

// ť �Լ�


void InitQueue(Queue* q, int capacity) {
	q->data = (int*)malloc(sizeof(int) * capacity);
	q->front = 0;
	q->rear = 0;
	q->capacity = capacity;
}

bool isFull(Queue* q) {
	//if (sizeof(q->data) == 4 * q->capacity) {
	//	return true;
	//} Ʋ������, int*�� �׻� ������ ũ�⸦ ��ȯ�Ұ���, 4 or 8 
	/*if (q->rear + 1 == q->front) {
		����ť�� �ƴϸ� ����, ����ť�� �迭�� �糡�� ����� ��ó�� ������.rear�� ����������
		0���� ���ư�����.
	}*/
	return ((q->rear + 1 % q->capacity) == q->front);

}

bool isEmpty(Queue* q) {
	return q->front == q->rear;
	// front�� rear�� ��������ġ�̸� �� ť��(��� �� ��)

}

void EnQueue(Queue* q, int item) {
	if (isFull(q) == true) {
		printf("Queue�� �� á���ϴ�\n");
		return;
	}

	q->data[q->rear] = item; //�ش� �ε����� item���� ����
	q->rear = (q->rear + 1) % q->capacity; //q.rear�� ��ȯ��Ű�� ���� ������ �������� �����ؾ���

}

int DeQueue(Queue* q) {
	if (isEmpty(q) == true) {
		printf("Queue�� ������ϴ�");
		return QueueError;
	}

	int item = q->data[q->front];	
	q->front = (q->front + 1) % q->capacity;
	return item;
}

void printQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue�� ������ϴ�");
		return;
	}
	printf("Queue ����: ");
	int i = q->front;

	while (i != q->rear) {
		printf("%d", q->data[i]);
		i = (i + 1) % q->capacity;
	}
	// ť�� ���� ���Ҹ� front���� rear���� ���;

	printf("\n");
}