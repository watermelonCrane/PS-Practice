#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string tmp;
        cin >> tmp;
        cout << tmp[0] - 48 + tmp[2] - 48 << "\n";
    }
    
    return 0;
}