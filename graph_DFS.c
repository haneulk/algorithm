#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n; //정점의 개수
vector<int> graph[101]; //그래프 표현 벡터
int visit[100] = {};	//방문여부를 나타내는 배열
int i = 0;

void DFS(int p) {
	visit[p] = 1;	//방문한 정점 1 표시
	int s = graph[p].size();	//연결된 정점의 개수
	printf("정점의 개수 : %d\n", s);
	for (i = 0; i < s; i++) {
		if (visit[graph[p][i]] == 0) { // 방문할 곳이 0이면
			printf("%d -> %d\n", p, graph[p][i]);
			DFS(graph[p][i]);
		}
	}
}


int main() {

	int sp; //출발정점
	int edge; //간선의 개수
	int v1, v2; //간선을 표현하기 위한 두 정점

	scanf("%d %d %d", &n, &edge, &sp);
	for (i = 0; i < edge; i++) {
		scanf("%d %d", &v1, &v2); //간선 입력
		graph[v1].push_back(v2);	//그래프의 연결을 벡터로 표현
		graph[v2].push_back(v1);	//이제 양방향 연결
	}
	DFS(sp);
	return 0;
}
//참고사이트
//https://goo.gl/iG43tT
