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

bool isFull(Queue* q) {
	//if (sizeof(q->data) == 4 * q->capacity) {
	//	return true;
	//} 틀린구현, int*는 항상 고정된 크기를 반환할것임, 4 or 8 
	/*if (q->rear + 1 == q->front) {
		원형큐가 아니면 맞음, 원형큐는 배열의 양끝이 연결된 것처럼 동작함.rear가 끝까지가면
		0으로 돌아가야함.
	}*/
	return ((q->rear % q->capacity) == q->front);
	
}

bool isEmpty(Queue* q) {
	return q->front == q->rear;
		
}

void EnQueue(Queue* queue, int item) {
	
}


void main() {
	Queue myQueue;
}