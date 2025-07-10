#include <iostream>

int main() {
    int N;
    int size[6];
    int T, P;
    
    using namespace std;

    cin >> N;
    for (auto& x: size) {
        cin >> x;    
    }
    cin >> T >> P;

    // make first ouput
    int Tresult = 0;
    for (auto& x: size) {
        if (x == 0) continue;
        if (x % T == 0) Tresult += x / T;
        else Tresult += x / T + 1;
    }

    cout << Tresult << "\n";

    cout << N / P << " " << N % P;

    return 0;
}