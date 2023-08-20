//실패
//230820 : 어이없게 틀렸던 거였음. 출력함수를 만들어 놓고서 안쓰고 그냥 숫자만 출력했었음 ㅋㅋㅋ

#include <iostream>
#include <string>
#include <vector>

void print_FizzBuzz(int n) {
    if (n % 3 == 0) {
        if (n % 5 == 0) {
            std::cout << "FizzBuzz";
        }
        else {
            std::cout << "Fizz";
        }
    }
    else {
        if (n % 5 == 0) {
            std::cout << "Buzz";
        }
        else {
            std::cout << n;
        }
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    std::vector<std::string> v(3);
    std::vector<bool> isnum(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> v[i];
        if (v[i][0] < 58) isnum[i] = true;
        else false;
    }

    for (int i = 0; i < 3; i++) {
        if (isnum[i]) {
            int tmp = std::stoi(v[i]);
            print_FizzBuzz(tmp + 3 - i);
            break;
        }
    }

    return 0;
}