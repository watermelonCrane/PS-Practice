#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    
    vector<int> result(K);
    for (auto& x: result) {
        int tmp;
        cin >> tmp;
        int P = tmp * 100 / N;
        if (P >= 0 && P <= 4) {
            x = 0;
        }
        else if (P <= 11) {
            x = 1;
        }
        else if (P <= 23) {
            x = 2;
        }
        else if (P <= 40) {
            x = 3;
        }
        else if (P <= 60) {
            x = 4;
        }
        else if (P <= 77) {
            x = 5;
        }
        else if (P <= 89) {
            x = 6;
        }
        else if (P <= 96) {
            x = 7;
        }
        else if (P <= 100) {
            x = 8;
        }
        cout << x + 1 << ' ';
    }

    return 0;
}