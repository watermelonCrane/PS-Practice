#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    std::cin >> str;
    if (str == "A+") {
        std::cout << "4.3";
    }
    else if (str == "A0") {
        std::cout << "4.0";
    }
    else if (str == "A-") {
        std::cout << "3.7";
    }  
    else if (str == "B+") {
        std::cout << "3.3";
    }
    else if (str == "B0") {
        std::cout << "3.0";
    }
    else if (str == "B-") {
        std::cout << "2.7";
    }
    else if (str == "C+") {
        std::cout << "2.3";
    }
    else if (str == "C0") {
        std::cout << "2.0";
    }
    else if (str == "C-") {
        std::cout << "1.7";
    }
    else if (str == "D+") {
        std::cout << "1.3";
    }
    else if (str == "D0") {
        std::cout << "1.0";
    }
    else if (str == "D-") {
        std::cout << "0.7";
    }
    else if (str == "F") {
        std::cout << "0.0";
    }


    return 0;
}