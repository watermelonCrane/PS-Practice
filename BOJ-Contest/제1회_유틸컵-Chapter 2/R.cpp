#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& x: v) {
        cin >> x;
    }

    vector<int> vv(N);
    for (auto& x: vv) {
        cin >> x;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (vv[i] >= v[i]) count++;
    }

    cout << count;

    return 0;
}