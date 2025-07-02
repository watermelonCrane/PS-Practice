//성공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NM(int N, int M, vector<int>& v, vector<int>& vn) {
    if (v.size() == M) {
        for (auto& x: v) {
            cout << vn[x] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < N; i++) {
            v.push_back(i);
            NM(N, M, v, vn);
        }
    }
    v.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    vector<int> v;
    vector<int> vn(N);
    for (auto& x: vn) {
        cin >> x;
    }
    sort(vn.begin(), vn.end());

    NM(N, M, v, vn);

    return 0;
}