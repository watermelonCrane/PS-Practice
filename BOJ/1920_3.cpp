#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
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
        if (binary_search(Ns.begin(), Ns.end(), tmp)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}