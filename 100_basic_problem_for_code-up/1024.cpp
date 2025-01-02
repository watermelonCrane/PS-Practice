#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    for (auto& x: a) {
        cout << '\'' << x << '\'' << '\n';
    }

    return 0;
}