#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B;
    for(;;) {
        cin >> A >> B;
        if (A == 0 && B==0) break;
        if (A > B) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}