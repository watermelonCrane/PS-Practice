#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> hex >> n;
    for (int i = 1; i <= 15; i++) {
        cout << uppercase << hex << n;
        cout << '*';
        cout << i;
        cout << '=';
        cout << n * i << '\n';
    }
}