//수학적으로 접근하는 방법, binary search를 이용하는 방법 등이 있단다.
//수학적인 방법을 검색해보았다.
//일단 규칙을 찾을 수 있는데... https://lighter.tistory.com/147
//실패 왜?

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int count = 0;
        for (int i = 2; i < floor(sqrt(2 * N + 1 / 4) - 1 / 2); i++) {
            if ((N - (i * (i + 1)) / 2) % i == 0) count++;
        }

        cout << count << '\n';

    }

    return 0;
}