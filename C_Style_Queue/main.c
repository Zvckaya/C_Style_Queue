#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int* data; //�迭������
	int front; // ������ ���� ��ġ
	int rear; // ������ ���� ��ġ
	int capacity; // �ִ�ũ��
} Queue;

bool isFull(Queue* q) {
	//if (sizeof(q->data) == 4 * q->capacity) {
	//	return true;
	//} Ʋ������, int*�� �׻� ������ ũ�⸦ ��ȯ�Ұ���, 4 or 8 
	/*if (q->rear + 1 == q->front) {
		����ť�� �ƴϸ� ����, ����ť�� �迭�� �糡�� ����� ��ó�� ������.rear�� ����������
		0���� ���ư�����.
	}*/
	return ((q->rear % q->capacity) == q->front);
	
}

bool isEmpty(Queue* q) {
	return q->front == q->rear;
	// front�� rear�� ��������ġ�̸� �� ť��(��� �� ��)
		
}

void EnQueue(Queue* q, int item) {
	if (isFull(q) == true)
		printf("Queue�� �� á���ϴ�\n");
	
	q->data[q->rear] = item; //�ش� �ε����� item���� ����
	q->rear = (q->rear + 1) % q->capacity; //q.rear�� ��ȯ��Ű�� ���� ������ �������� �����ؾ���

}


void main() {
	Queue myQueue;
}