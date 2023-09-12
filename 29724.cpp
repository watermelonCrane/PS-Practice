//성공
#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    
    char T;
    int W, H, L;
    int Weight = 0;
    int AppleCost = 0;
    for (int i = 0; i < N; i++) {
        cin >> T >> W >> H >> L;
        if (T == 'A') {
            Weight += 1000;
            int Ws = W / 12;
            int Hs = H / 12;
            int Ls = L / 12;
            int number = Ws * Hs * Ls;
            Weight += number * 500;
            AppleCost += number * 4000;
        }
        else if (T == 'B') {
            Weight += 120 * 50;
        }
    }
    cout << Weight << '\n' << AppleCost;


    return 0;
}