#include <stdio.h>
#include <string.h>

char ar[15] = "174639";

int merge(char *ar, size_t len) {
	if (len < 2) return 0;

	//2개씩 묶어주는 작업
	size_t mid = len / 2;
	merge(ar, mid);	//왼쪽
	merge(ar + mid, len - mid);	//오른쪽

	char *buf = new char[len];	//버퍼 동적으로 할당
	int i = 0;
	int j = mid;
	int k = 0;

	while (i < mid && j < len) {
		buf[k++] = (ar[i] < ar[j]) ? ar[i++] : ar[j++];
	}
	while (i < mid) {
		buf[k++] = ar[i++];
	}
	while (j < len) {
		buf[k++] = ar[j++];
	}
	for (i = 0; i < len; i++) {
		ar[i] = buf[i];
	}
	delete[] buf;	//동적 메모리(heap) 해제

}
int main() {
	merge(ar, strlen(ar));

	printf("%s", ar);


	return 0;
}
