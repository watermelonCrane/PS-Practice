/* #include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, S;

    while (1) {
        cin >> N >> S;
        if (cin.eof() == true) break;
        N++;
        cout << S / N << "\n";
    }

    return 0;
} */

//왜인지는 모르겠지만 위의 코드는 문제에서 오답을 냈다.
//cin.eof()를 지원을 안한건지는 모르겠지만
//아래의 코드처럼 cin을 while의 조건안에 넣을 경우 작동을 했다.
//추측하기론 cin은 반환값이 있으며, eof일 경우 false를 반환하는 것 같다.
//정확한 내용은 찾지 못하였다.

#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, S;

    while (cin >> N >> S) {
        N++;
        cout << S / N << "\n";
    }

    return 0;
}
