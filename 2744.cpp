#include <iostream>
#include <string>
using namespace std;

void switch_word(string& str) {
    for (auto& x: str) {
        if (x >= 'a') {
            x = toupper(x);
        }
        else {
            x = tolower(x);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string wrd;
    cin >> wrd;
    
    switch_word(wrd);
    cout << wrd;

    return 0;
}