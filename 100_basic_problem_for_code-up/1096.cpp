#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> b(19, vector<int>(19, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        b[x - 1][y - 1] = 1;
    }
    for (auto& x: b) {
        for (auto& y: x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}