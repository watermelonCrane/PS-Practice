//성공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NM(int N, int M, vector<int>& v, int i, vector<int>& Ns) {
    if (v.size() == M) {
        for (auto& x: v) {
            cout << Ns[x] << ' ';
        }
        cout << "\n";
    }
    else {
        for (; i < N; i++) {
            v.push_back(i);
            NM(N, M, v, i + 1, Ns);
        }
    }
    v.pop_back();
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> Ns(N);
    for (auto& x: Ns) {
        cin >> x;
    }
    sort(Ns.begin(), Ns.end());

    vector<int> v;
    NM(N, M, v, 0, Ns);


    return 0;
}