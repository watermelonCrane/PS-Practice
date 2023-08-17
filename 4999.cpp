#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::string J, Doc;
    std::cin >> J >> Doc;
    
    if (J.size() >= Doc.size()) {
        std::cout << "go";
    }
    else {
        std::cout << "no";
    }

    return 0;
}