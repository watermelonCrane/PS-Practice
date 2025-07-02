//성공
#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, L;
    cin >> N >> L;
    cout << 1 << N;
    for (int i = 0; i < L - 2; i++) {
        cout << 1;
    }


    return 0;
}