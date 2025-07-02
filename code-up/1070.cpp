#include <iostream>
using namespace std;
int main() {

    int a;
    cin >> a;
    if (a == 12 || a == 1 || a == 2) cout << "winter";
    else if (a >= 3 && a <= 5) cout << "spring";
    else if (a >= 6 && a <= 8) cout << "summer";
    else cout << "fall";

    return 0;
}