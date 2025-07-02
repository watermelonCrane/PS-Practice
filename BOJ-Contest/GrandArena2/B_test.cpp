//어쩔 수 없이 시간초과

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int FB(int i) {         //0: FizzBuzz, 1: Fizz, 2: Buzz, -1: i
    if (i % 3 == 0) {
        if (i % 5 == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        if (i % 5 == 0) {
            return 2;
        }
        else {
            return -1;
        }
    }
}

int main() {
    vector<string> v(3);
    vector<string> ex;

    ex.push_back("dummy");
    ex.push_back("Pizz");
    ex.push_back("Buzz");
    for (int i = 3; i < 100000000; i++) {
        switch (FB(i)) {
        case -1:
            ex.push_back(to_string(i));
            break;
        case 0:
            ex.push_back("FizzBuzz");
            break;
        case 1:
            ex.push_back("Fizz");
            break;
        case 2:
            ex.push_back("Buzz");
            break;
        default:
        break;
        }
        //if (i < 3) continue;        //3개 이상 쌓일때까지

        if (ex[i].back() > 57) {
            if (ex[i - 1].back() > 57) {
                if (ex[i - 2].back() > 57) {
                    cout << i;
                }
            }
        }

    }

    return 0;
}