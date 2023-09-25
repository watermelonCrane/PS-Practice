#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int W, A, B, X;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> X;
        W = A * (X - 1) + B;
        cout << W << '\n';
    }

    return 0;
}