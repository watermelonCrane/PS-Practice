//성공
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N;
    cin >> S;
    int c = N / 2;

    if (N % 2) {
        string str1, str2;
        str1 = S.substr(0, c);
        reverse(S.begin(), S.end());
        str2 = S.substr(0, c);
        S = str1 + str2;
    }

    sort(S.begin(), S.end());

    bool chek = false;
    for (int i = 1; i < S.size(); i++) {
        if (chek == false) {
            if (S[i - 1] == S[i]) chek = true;
            else {
                chek = false;
                break;
            }
        }
        else {
            chek = false;
        }
    }
    if (chek == false) cout << "No";
    else cout << "Yes";

    return 0;
}