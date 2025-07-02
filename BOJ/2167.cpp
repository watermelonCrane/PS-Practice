#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int** arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cin >> arr[i][k];
        }
    }

    int K;
    cin >> K;

    int i, j, x, y;
    while (K--) {
        cin >> i >> j >> x >> y;
        int sum = 0;
        for (int a = i - 1; a < x; a++) {
            for (int b = j - 1; b < y; b++) {
                sum += arr[a][b];
            }
        }
        cout << sum << "\n";
    }


    return 0;
}