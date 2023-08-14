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

    for (auto& x : v) {
        cin >> x;
    }

    ex.push_back("dummy");
    for (int i = 1; ; i++) {
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
        if (i < 3) continue;        //3개 이상 쌓일때까지

        int j = 2;
        for (int k = i; j > -1; k--, j--) {
            if (ex[k] == v[j]) {
                continue;
            }
            else break;
        }
        if (j == -1) {
            i++;
            switch (FB(i)) {
            case -1:
                cout << i;
                break;
            case 0:
                cout << "FizzBuzz";
                break;
            case 1:
                cout << "Fizz";
                break;
            case 2:
                cout << "Buzz";
                break;
            default:
            break;
            }
            return 0;
        }

    }

    return 0;
}