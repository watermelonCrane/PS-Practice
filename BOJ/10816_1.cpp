//무식하게 배열 크기를 늘려서 사용
//음수를 없애기 위해 큰 값을 더해주었다.

#include <iostream>
#include <vector>

using namespace std;

int Ns[20000001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        Ns[tmp + 10000000]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        cout << Ns[tmp + 10000000];
        cout << ' ';
    }

}