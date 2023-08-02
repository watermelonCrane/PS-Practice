#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> m1(N, vector<int>(M));
    vector<vector<int>> m2(N, vector<int>(M));

    int tmp;

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cin >> tmp;
            m1[i][k] = tmp;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cin >> tmp;
            m2[i][k] = tmp;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cout << m1[i][k] + m2[i][k] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}