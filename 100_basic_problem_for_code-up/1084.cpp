#include <iostream>
using namespace std;

int main() {

    int n, m, l;
    cin >> n >> m >> l;

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                cout << i << ' ' << j << ' ' << k << '\n';
                count++;
            }
        }
    }
    cout << count;


    return 0;
}