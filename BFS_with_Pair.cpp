#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int N, K;
	queue<pair<int, int>> q;
	int visit[100001] = {};
	int pos = 0, depth = 0;
	
	scanf("%d %d", &N, &K);
	q.push({N,0});	//q.push(pair<int, int>(N, 0));	//같음

	while (!q.empty()) {
		pos = q.front().first;
		depth = q.front().second;
		q.pop();
		
		if (pos == K) break;	//찾은 값이면 while문 끝냄

		if (pos<0 || pos>100000) continue;	//N범위 넘으면 continue이하 건너뛰고 다음 while차례로
		if (visit[pos]) continue;			//이미 찾은 정점이면 visit가 1이므로 continue이하 건너뜀

		visit[pos] = true;

		q.push({ pos - 1, depth + 1 });
		q.push({ pos + 1, depth + 1 });
		q.push({ pos * 2, depth + 1 });
	}
	
	printf("%d\n", q.front().second);		//가장 빠른 초 = 깊이

	return 0;
}
