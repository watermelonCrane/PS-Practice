#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NM(int N, int M, vector<int>& v, vector<int>& list, int i) {
    if (v.size() == M) {
        for (auto& x: v) {
            cout << list[x] << ' ';
        }
        cout << '\n';
    }
    else {
        for (; i < N; i++) {
            v.push_back(i);
            NM(N, M, v, list, i);
        }
    }
    v.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> list(N);
    for (auto& x: list) {
        cin >> x;
    }
    sort(list.begin(), list.end());

    vector<int> v;
    NM(N, M, v, list, 0);

    return 0;
}