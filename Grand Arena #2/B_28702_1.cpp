//정답

#include <iostream>
#include <string>
using namespace std;

void printFB(int num) {
    if (num % 5 == 0) {       //5의 배수라면
        if (num % 3 == 0) {
            cout << "FizzBuzz";
        }
        else {
            cout << "Buzz";
        }
    }
    else {
        if (num % 3 == 0) {
            cout << "Fizz";
        }
        else {
            cout << num;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

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