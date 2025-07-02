//성공
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int gasung = B / A;
    gasung *= 3;

    cout << C * gasung;

    return 0;
}