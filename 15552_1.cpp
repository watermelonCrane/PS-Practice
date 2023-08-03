//ver2
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    int T;
    std::cin >> T;
    int a, b;
    for (int i = 0; i < T; i++) {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }

    return 0;
}