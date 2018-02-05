#include <cstdio>
using namespace std;

int i, j, k, N, in;
int result[101][101] = {};

int main() {
	//플로이드로 풀기
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &result[i][j]);
		}
	}

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (result[i][k] && result[k][j]) {
					result[i][j] = 1;
				}
			}
		}
	}
	
	//출력
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}
