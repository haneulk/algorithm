#include <stdio.h>

int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += i;
	return ret;
}

int recursiveSum(int n) {
	if (n == 1) return 1;	//기저사례 : 더이상 쪼개지지 않는 가장 작업들
	return n + recursiveSum(n - 1);
}

int main() {
	printf("%d %d\n", sum(5), recursiveSum(5));
	return 0;
}
