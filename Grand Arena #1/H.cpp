//시간초과


#include <iostream>
#include <vector>

using namespace std;

void first_command(int r, int v, vector<vector<int>>& matrix) {
    int size = matrix[0].size();
    for (int i = 0; i < size; i++) {
        matrix[r - 1][i] += v;
    }
}
void second_command(int c, int v, vector<vector<int>>& matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        matrix[i][c - 1] += v;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> matrix(N, vector<int>(M, 0));

    vector<int> cmd(3);
    for (int i = 0; i < Q; i++) {
        cin >> cmd[0] >> cmd[1] >> cmd [2];
        if (cmd[0] == 1) {
            first_command(cmd[1], cmd[2], matrix);
        }
        else {
            second_command(cmd[1], cmd[2], matrix);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cout << matrix[i][k] << " ";
        }
        cout << '\n';
    }

    return 0;
}