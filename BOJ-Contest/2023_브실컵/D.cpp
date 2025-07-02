//성공
#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int S, N, M;
    cin >> S >> N >> M;

    int data = 0;
    int capacity = S;
    for (int i = 0; i < N + M; i++) {
        int tmp;
        cin >> tmp;
        if (tmp) {
            data++;
            if (data > capacity) {
                capacity *= 2;
            }
        }
        else {
            data--;
        }
    }

    cout << capacity;


    return 0;
}