//성공
#include <iostream>
#include <vector>
using namespace std;

bool operator<(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first && a.second < b.second;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> listmob(N);
    for (auto& a: listmob) {
        int x, y;
        cin >> x >> y;
        a = {x, y};
    }

    vector<int> rank(N, 0);
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (k == i) continue;
            if (listmob[i] < listmob[k]) rank[i]++;
        }
    }

    for (auto& x: rank) {
        cout << x + 1 << ' ';
    }

    return 0;
}