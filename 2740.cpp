//정답
//행렬의 곱 방법을 알아두자.
#include <vector>
#include <iostream>
using namespace std;

int multi(int i, int j, vector<vector<int>>& m1, vector<vector<int>>& m2) {
    int result = 0;
    int size = m1[i].size();
    for (int n = 0; n < size; n++) {
        result += m1[i][n] * m2[n][j];
    }

    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matrix1(N, vector<int>(M));
    for(auto& x: matrix1) {
        for (auto& y: x) {
            cin >> y;
        }
    }

    int K;
    cin >> M >> K;
    vector<vector<int>> matrix2(M, vector<int>(K));
    for (auto& x : matrix2) {
        for (auto& y : x) {
            cin >> y;
        }
    }

    vector<vector<int>> newmatrix(N, vector<int>(K));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            newmatrix[i][j] = multi(i, j, matrix1, matrix2);
        }
    }

    for (auto& x : newmatrix) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }



    return 0;
}