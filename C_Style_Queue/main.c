#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int* data; //배열포인터
	int front; // 데이터 꺼낼 위치
	int rear; // 데이터 넣을 위치
	int capacity; // 최대크기
} Queue;


