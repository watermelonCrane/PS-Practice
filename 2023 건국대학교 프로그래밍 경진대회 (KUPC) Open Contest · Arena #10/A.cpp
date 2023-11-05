//성공
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, L;
    cin >> N >> L;
    vector<int> v(N, 0);
    for (auto& x: v) {
        char a = 3;
        for (int i = 0; i < L; i++) {
            char pa = a;
            cin >> a;
            if (a == '1' && a != pa) x++;
        }
    }

    sort(v.begin(), v.end(), greater<int>());

    int result = 0;
    for (auto it = v.begin(); it == v.begin() || (*it == *(it - 1) && it != v.end()); it++) {
        result++;
    }

    cout << v[0] << ' ' << result;

    return 0;
}