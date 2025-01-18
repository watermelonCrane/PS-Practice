#include <iostream>
using namespace std;

int main() {

    double h, b, c, s;
    cin >> h >> b >> c >> s;
    double bit = h * b * c * s;
    bit /= 8;
    bit /= 1024;
    bit /= 1024;


    cout << fixed;
    cout.precision(1);
    cout << bit << " MB";

    return 0;
}