#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myQueue.h"


void main() {
	Queue myQueue;
	InitQueue(&myQueue, 10);
	for (int i = 1;i < 5;i++) {
		EnQueue(&myQueue, i);
	}

	printQueue(&myQueue);
	
	printf("%d \n", DeQueue(&myQueue));
	printf("%d \n", DeQueue(&myQueue));
	printf("%d \n", DeQueue(&myQueue));
	printf("%d \n", DeQueue(&myQueue));
	printf("%d \n", DeQueue(&myQueue));


}