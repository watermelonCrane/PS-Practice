#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int H, W, N;
        cin >> H >> W >> N;

        int Y = N % H;
        int X = N / H + 1;
        if (Y == 0) {
            Y = H;
            X--;
        }

        cout << Y << setfill('0') << setw(2) << X << '\n';
            
    }


    return 0;
}