#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int i = 0;
    for (i = 1; !(i % a == 0 && i % b == 0 && i % c == 0); i++);
    cout << i;

    return 0;
}