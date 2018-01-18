#include <iostream>
#include <vector>
using namespace std;

//n : 전체 원소의 수
//picked : 지금까지 고른 원소의 수
//toPick : 더 고를 원소의 수
//일 때, 앞으로 toPick개의 원소를 고르는 모든 방법 출력
void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		for (int nIndex = 0; nIndex < picked.size(); ++nIndex) {
			printf("%d ", picked[nIndex]);
		}
		printf("\n");
		return;	//아무것도 반환하지 않음/ 단순히 함수를 종료시키기 위함
	}
	//고를 수 있는 가장 작은 번호 계산
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	//원소 하나를 고름
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
	
}

int main() {
	int n = 7;
	vector<int> v;
	pick(n, v, 4);
	return 0;
}
