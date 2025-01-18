#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 3 != 0) cout << i + 1 << ' ';
    }

    return 0;
}