#include <iostream>
#include <cmath>

long long cal(long long A, long long B) {
    A *= A;
    B *= B;
    return A - B;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    long long A, B;
    std::cin >> A >> B;
    std::cout << cal(A, B);

    return 0;
}