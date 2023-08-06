#include <iostream>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;
    while (1) {
        std::getline(std::cin, str, '\n');
        if (str == "") break;
        std::cout << str << '\n';
    }


}