//성공
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B;
    cin >> A >> B;
    int K, X;
    cin >> K >> X;

    int count = 0;
    for (int i = A; i <= B; i++) {
        if (abs(K - i) <= X) count++;
    }

    if (count > 0) cout << count;
    else cout << "IMPOSSIBLE";

    return 0;
}