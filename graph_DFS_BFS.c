#include <cstdio>
#include <queue>

using namespace std;

int graph[1001][1001] = {};
int visit[1001] = {};

//인접행렬을 이용한 DFS, BFS
void DFS(int N, int num) {
	printf("%d ", num);
	for (int i = 1; i <= N; i++) {
		if (graph[num][i] == 1 && visit[i] == 0) {	//연결이되고(1), 방문하지않은(0) 정점
			visit[i] = 1;
			DFS(N,i);
		}
	}
}

void BFS(int N, int start) {
	queue<int> Q;
	Q.push(start);
	visit[start] = 1;
	while (!Q.empty()) {
		int num = Q.front();
		printf("%d ", num);
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[num][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				Q.push(i);
			}
		}
	}
	printf("\n");
}

int main() {
	int N, M, start;
	int v1, v2;

	scanf("%d %d %d", &N, &M, &start);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;	//정점 양방향 연결
	}
	visit[start] = 1;	//시작점 방문표시
	DFS(N, start);
	printf("\n");
	for (int i = 1; i <= N; i++) {	//visit배열 초기화, 초기화 범위 주의할것!
		visit[i] = 0;
	}
	BFS(N, start);
	return 0;
}
