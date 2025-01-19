#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(23, 0);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[tmp - 1]++;
    }
    for (auto& x: v) {
        cout << x << ' ';
    }

    return 0;
}