//성공
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    char c;
    string str;
    int count = 0;

    while(1) {
        count = 0;
        getline(cin, str);
        if (str == "#") break;
        for (auto& x: str) {
            c = x;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                count++;
            }
        }
        cout << count << '\n';

    }

    return 0;
}