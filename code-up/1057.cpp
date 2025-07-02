#include <iostream>

int main() {
    bool a, b;
    std::cin >> a >> b;
    std::cout << ((!a && !b) || (a && b));

}