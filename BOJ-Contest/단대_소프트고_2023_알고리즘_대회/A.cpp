//성공
#include <iostream>
#include <string>
using namespace std;

int findDKSH(string& DKSH, size_t pos) {
    pos = DKSH.find("DKSH", pos);
    if (pos == string::npos) return 0;
    else {
        return findDKSH(DKSH, pos + 4) + 1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string DKSH;
    cin >> DKSH;

    cout << findDKSH(DKSH, 0);
    

    return 0;
}