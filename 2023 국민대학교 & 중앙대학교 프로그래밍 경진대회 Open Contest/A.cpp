//정답
#include <iostream>

int main() {
    int W, H;
    float A;

    std::cin >> W >> H;

    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << static_cast<float>(W * H) / 2.0f;

    return 0;
}