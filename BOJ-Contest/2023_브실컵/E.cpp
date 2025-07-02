//성공
#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    int su = N - M * K;

    cout << (su >= 0 ? su : 0) << " " << (su + M - 1 >= 0 ? su + M - 1 : 0);


    return 0;
}