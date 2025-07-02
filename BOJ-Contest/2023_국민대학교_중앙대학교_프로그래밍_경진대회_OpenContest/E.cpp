//미완, 시험 종료
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> b(N);
    for (auto& x: b) {
        cin >> x;
    }

    vector<pair<int, int>> j(M);
    vector<int> jdie(M, 0);
    for (auto& x: j) {
        cin >> x.first >> x.second;
    }

    for (int P = 1; ; P++) {
        int i = 0;
        for (auto& x: b) {
            for (; abs(x - j[i].first) * j[i].second > P; i++);
        }
        if (i < M) continue;
        else {
            cout << P;
            break;
        }
    }

    return 0;
}