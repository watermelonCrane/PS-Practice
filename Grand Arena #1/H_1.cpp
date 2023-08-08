//단순하게 행열을 만드는 것이 아니라
//각 행이 몇번 더해졌는지 생각하면 된다. 어차피 시작은 0이니까!

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> vN(N, 0), vM(M, 0);

    int t, rc, v;
    for (int i = 0; i < Q; i++) {
        cin >> t >> rc >> v;
        if (t == 1) {
            vN[rc-1] += v;
        }
        else {
            vM[rc-1] += v;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cout << vN[i] + vM[k] << " ";
        }
        cout << "\n";
    }


    return 0;
}