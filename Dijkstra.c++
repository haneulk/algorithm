#include <cstdio>
#include <queue>
#include <functional> //우선순위 큐를 쓰기위해 필요
#include <vector>
#include <cstring>

#define INF 0x7f
using namespace std;
typedef pair<int, int> P;	//pq 선언시 너무 지저분하니까 깔끔하게 define함
//C++11로 채점가능(향상된 for문, 우선순위큐 템플릿 사용했으니까!)
int main() {
	int V, E, K;
	int i;
	bool visit[20001] = { false };	//방문여부
	int dist[20001]; //노드까지의 거리(weight)를 저장하는 배열
	vector<P> adj[20001]; //(거리(=weight), 노드번호)로 인접 노드를 저장
	priority_queue<P, vector<P>, greater<P>> pq;	//거리가 가장 짧은 노드를 빼내기 위한 우선순위큐, (거리, 노드번호)로 저장됨! adj와는 다름!!

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	int from, to, weight;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		adj[from].push_back(P(weight, to));	//push_back은 마지막에 원소를 추가
	}
	for (i = 1; i <= V; i++) {	//모든 노드를 최대치로 초기화
		dist[i] = INF;
	}
	dist[K] = 0; //시작노드는 0으로 초기화
	pq.push(make_pair(0, K));
	while (!pq.empty()) {
		int cost = pq.top().first;	//가중치(=거리)
		int now = pq.top().second;	//현재 노드
		pq.pop();
		if (dist[now] < cost) continue;
		if (dist[now] == cost && visit[now] == true) continue;
		visit[now] = true;
		
		//향상된 for문 형식
		//매번 순환문이 반복될때마다 이 변수(next)에 adj[now]값이 대입됨
		//콜론은 왼쪽에 있는 변수에 오른쪽에 있는 것의 각 원소의 값이 대입된다는 것을 뜻함
		for (P next : adj[now]) {	//최단거리를 찾기위해 다음 노드를 비교하는 단계
			if (dist[next.second] > next.first + cost) {
				pq.push(make_pair(next.first + cost, next.second));	//우선순위큐에 push할때 pair로 넣는거 중요!!
				dist[next.second] = next.first + cost;
			}
		}
	}
	for (i = 1; i <= V; i++) {
		if (dist[i] >= INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);	//최단 경로의 경로값을 출력
	}
	return 0;
}
