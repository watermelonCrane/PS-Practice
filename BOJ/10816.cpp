#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Ns(N);
    for (auto& x: Ns) {
        cin >> x;
    }
    sort(Ns.begin(), Ns.end());


    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        auto bound = equal_range(Ns.begin(), Ns.end(), tmp);
        cout << bound.second - bound.first;
        cout << ' ';
    }

    return 0;
}