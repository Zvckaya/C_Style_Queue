#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int* data; //배열포인터
	int front; // 데이터 꺼낼 위치
	int rear; // 데이터 넣을 위치
	int capacity; // 최대크기
} Queue;

void InitQueue(Queue* q, int capacity) {
	q->data = (int*)malloc(sizeof(int) * capacity);
	q->front = 0;
	q->rear = 0;
	q->capacity = capacity;
}

bool isFull(Queue* q) {
	//if (sizeof(q->data) == 4 * q->capacity) {
	//	return true;
	//} 틀린구현, int*는 항상 고정된 크기를 반환할것임, 4 or 8 
	/*if (q->rear + 1 == q->front) {
		원형큐가 아니면 맞음, 원형큐는 배열의 양끝이 연결된 것처럼 동작함.rear가 끝까지가면
		0으로 돌아가야함.
	}*/
	return ((q->rear+1 % q->capacity) == q->front);
	
}

bool isEmpty(Queue* q) {
	return q->front == q->rear;
	// front와 rear가 동일한위치이면 빈 큐임(모두 뺀 것)
		
}

void EnQueue(Queue* q, int item) {
	if (isFull(q) == true) {
		printf("Queue가 꽉 찼습니다\n");
		return;
	}
	
	q->data[q->rear] = item; //해당 인덱스를 item으로 설정
	q->rear = (q->rear + 1) % q->capacity; //q.rear를 순환시키기 위해 나머지 연산으로 동작해야함

}

int DeQueue(Queue* q) {
	if (isEmpty(q) == true) {
		printf("Queue가 비었습니다");
		return -1;
	}

	int item = q->data[q->front];
	q->front = (q->front + 1) % q->capacity;
	return item;
}



void main() {
	Queue myQueue;
	InitQueue(&myQueue, 10);
	for (int i = 1;i < 5;i++) {
		EnQueue(&myQueue, i);
	}
	
	printf("%d \n", DeQueue(&myQueue));
	printf("%d \n", DeQueue(&myQueue));
	printf("%d \n", DeQueue(&myQueue));


}