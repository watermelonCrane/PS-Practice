//성공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NM(int N, int M, vector<int>& su, vector<int>& result) {
    if (result.size() == M) {
        for (auto& x : result) {
            cout << su[x] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < N; i++) {
            if (find(result.begin(), result.end(), i) != result.end()) continue;
            result.push_back(i);
            NM(N, M, su, result);
        }
    }
    result.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> su(N);
    for (auto& x : su) {
        cin >> x;
    }
    sort(su.begin(), su.end());

    vector<int> result;
    NM(N, M, su, result);

    return 0;
}