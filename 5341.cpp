//성공
#include <iostream>
using namespace std;

int main() {

    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        if (N % 2) {
            int np = N - 1;
            cout << (np + 1) * (np / 2) + N << '\n';
        }
        else {
            cout << (N + 1) * (N / 2) << '\n';
        }
    }    

    return 0;
}