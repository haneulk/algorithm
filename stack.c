#include <stdio.h>

#define MAX 5
int sp, arr[MAX] = {},i=0;

int push(int data) {	//push 함수
	if (sp >= MAX) {
		printf("stack overflow!!!\n");
		return -1;
	}
	arr[sp] = data;
	sp++;
	return data;
}

int pop() {	//pop 함수
	int data;
	if (sp <= 0) {
		printf("stack underflow!!\n");
		return -1;
	}
	sp--;
	data = arr[sp];
	return data;
}

void print() {	//스택 출력
	for (i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

void init() {	//스택 초기화
	sp = 0;
}

int main() {
	int r;
	sp = 0;

	printf("[ push 3 4 5 6 7 ]\n");
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	print();

	printf("[ push 8 -> it will be 'overflow' ]\n");
	push(8);
	print();

	printf("[ pop x 1 and push 8 ]\n");
	r = pop();
	push(8);
	printf("pop value : %d\n", r);
	print();

	printf("[ init and pop -> it will be 'underflow' ]\n");
	init();
	pop();
	return 0;
}
