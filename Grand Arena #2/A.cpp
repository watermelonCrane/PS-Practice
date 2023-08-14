//성공
#include <iostream>
#include <cmath>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int first, third;
    first = third = 0;
    for (int i = 1; i <= N; i++) {
        first += i;
        third += pow(i, 3);
    }
    std::cout << first << '\n' << (int)pow(first, 2) << '\n' << third;

    return 0;
}