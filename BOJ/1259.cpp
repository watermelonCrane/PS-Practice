//성공
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (1) {
        string str;
        cin >> str;
        if (str == "0") break;

        string::iterator front = str.begin();
        string::iterator back = str.end(); back--;

        while (front < back) {
            if (*front != *back) {
                cout << "no\n";
                break;
            }
            front++;
            back--;
        }
        if (!(front < back)) {
            cout << "yes\n";
        }
    }

    return 0;
}