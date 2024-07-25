#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    long long result = 1;
    while (N) {
        result *= N;
        N--;
    }

    cout << result;

    return 0;
}