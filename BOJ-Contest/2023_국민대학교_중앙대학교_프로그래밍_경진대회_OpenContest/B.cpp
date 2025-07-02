//성공
#include <iostream>
using namespace std;

int main() {
    int N;
    int S = 0;
    int Stmp = 0;
    int tmp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (Stmp > S) {
                S = Stmp;
            }
            Stmp = 0;
            continue;
        }
        Stmp++;
    }
    cout << ((S > Stmp) ? S : Stmp);

    return 0;
}