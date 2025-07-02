#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            cout << i << ' ' << k << '\n';
        }
    }
    
    return 0;
}