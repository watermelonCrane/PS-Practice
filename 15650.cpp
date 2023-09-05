#include <iostream>
#include <vector>
using namespace std;

void NM(int N, int M, vector<int>& v) {
    if (v.size() == M) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (!v.empty() && v.back() >= i) continue;
            v.push_back(i);
            NM(N, M, v);
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
    NM(N, M, v);

    return 0;
}