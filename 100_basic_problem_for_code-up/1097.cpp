#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<vector<int>> badook(19, vector<int>(19, 0));
    for (auto& x: badook) {
        for (auto& y: x) {
            cin >> y;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (auto& t: badook[x - 1]) {
            if (t == 1) t = 0;
            else t = 1;
        }
        for (auto& t: badook) {
            if (t[y - 1] == 1) t[y - 1] = 0;
            else t[y - 1] = 1;
        }
    }
    for (auto& x: badook) {
        for (auto& y: x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}