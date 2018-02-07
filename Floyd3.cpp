#include <cstdio>
#include <algorithm>  //max와 min사용할수있음
using namespace std;

//int min(int a, int b) { return (a > b ? b : a); }
//int max(int a, int b) { return (a > b ? a : b); }
int main() {
	int i, j, k, t;
	int graph[101][101] = {};
	int N, M, X;

	scanf("%d %d %d", &N, &M, &X);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i!=j) graph[i][j] = 1000;
		}
	}
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &j, &k, &t);
		graph[j][k] = min(graph[j][k], t);
	}
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	int result = 0;
	for (i = 1; i <= N; i++) {
		int tmp = graph[i][X] + graph[X][i];
		result = max(result, tmp);
	}
	printf("%d\n", result);
	return 0;
}
