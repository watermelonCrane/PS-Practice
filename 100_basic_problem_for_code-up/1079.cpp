#include <iostream>
using namespace std;

int main() {

    char a;
    for (;;) {
        cin >> a;
        cout << a << '\n';
        if (a == 'q') break;
    }

    return 0;
}