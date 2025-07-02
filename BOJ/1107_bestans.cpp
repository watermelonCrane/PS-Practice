//제출자들의 코드중에서 내가생각하는 모범답안시리즈 "bestans"
//제출자: alreadysolved
//모범답안 사유: 최적화 레전드
//알개된 부분:
//1. algorithm헤더의 min함수.
//2. do while구문의 사용
//3. 43번 라인 최소값을 구하는 과정의 최적화 부분. 내가 생각하지 못했었다.

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int button[10];

bool chk(int n) {
	if (n < 0) return 0;
	do {
		if (button[n % 10]) return 0;
		n /= 10;
	} while (n);
	return 1;
}

int len(int n) {
	int l = 0;
	do {
		l++;
		n /= 10;
	} while (n);
	return l;
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int a; scanf("%d", &a);
		button[a] = 1;
	}
	int t = abs(100 - N);
	int cnt = 0;
	while (cnt < t) {
		if (chk(N - cnt)) {
			cnt += len(N - cnt);
			break;
		}
		else if (chk(N + cnt)) {
			cnt += len(N + cnt);
			break;
		}
		cnt++;
	}
	printf("%d", min(cnt, t));
}