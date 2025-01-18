#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; ; i++) {
        int result = 0;
        if (i % 2 == 0) {
            result = (1 + i) * (i / 2);
        }
        else {
            result = (1 + i) * (i / 2) + (i / 2 + 1);
        }
        
        if (result >= n) {
            cout << result;
            break;
        }
    }
    
    return 0;
}