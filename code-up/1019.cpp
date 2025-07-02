#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    char dot;
    cin >> a >> dot >> b >> dot >> c;

    cout.width(4);
    cout.fill('0');
    cout << a << dot;
    cout.width(2);
    cout.fill('0');
    cout << b << dot;
    cout.width(2);
    cout.fill('0');
    cout << c;

    return 0;
}