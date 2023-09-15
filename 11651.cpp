//성공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (auto& x: v) {
        cin >> x.second >> x.first;
    }

    sort(v.begin(), v.end());

    for (auto& x: v) {
        cout << x.second << ' ' << x.first << '\n';
    }

    return 0;
}