//정답

#include <iostream>
#include <string>
using namespace std;

bool isMultipleof3(int num) {
    while (num > 3) {
        num %= 3;
    }
    if (num == 3 || num == 0) {
        return true;
    }
    else {
        return false;
    }
}

void printFB(int num) {
    if (num % 10 == 0 || num % 10 == 5) {       //5의 배수라면
        if (isMultipleof3(num) == true) {
            cout << "FizzBuzz";
        }
        else {
            cout << "Buzz";
        }
    }
    else {
        if (isMultipleof3(num) == true) {
            cout << "Fizz";
        }
        else {
            cout << num;
        }
    }
}

int main() {
    string str[3];
    int w = -1;
    for (int i = 0; i < 3; i++) {
        cin >> str[i];
        if (str[i][0] < 58) w = i;
    }

    int transNum = stoi(str[w]);
    printFB(transNum + 3 - w);


    return 0;
}