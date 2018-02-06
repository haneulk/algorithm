#include <cstdio>
using namespace std;
//백준2606번 바이러스 문제
int main() {
	int N, M;
	int i, j, k, count=0;
	int graph[101][101] = {};
	scanf("%d", &N);
	scanf("%d", &M);
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			graph[i][j] = 100;
		}
	}

	for (i = 1; i <= M; i++) {
		scanf("%d %d", &j, &k);
		graph[j][k] = graph[k][j] = 1;
	}

	for (i = 1; i <= N; i++) graph[i][i] = 0;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <=N; i++) {
			for (j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	for (i = 1; i <= N; i++) {
		if (graph[1][i] > 0 && graph[1][i] < 100) {	//1번 컴퓨터가 감염시킨 컴퓨터의 수
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
