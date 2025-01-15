#include <iostream>
using namespace std;
int main() {

    int tmp;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        if (tmp % 2 == 0) cout << "even\n";
        else cout << "odd\n";
    }

    return 0;
}