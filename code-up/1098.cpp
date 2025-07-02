/// 아니 도대체 "막대에 있는 설탕과자 이름 아래에 있는 번호를 뽑으면" 무슨말임 도대체, 이해하기 어렵게 중첩의 중첩의 중첩으로 문제를 적어놨음;;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> m(h, vector<int>(w, 0));
    
    for (int i = 0; i < n; i++) {
        int l, d, x, y;
        cin >> l >> d >> x >> y;

        if (d == 0) {
            for (int k = 0; k < l; k++) {
                m[x - 1][k + y - 1] = 1;
            }
        } else {
            for (int k = 0; k < l; k++) {
                m[k + x - 1][y - 1] = 1;
            }
        }
    }

    for (auto& x: m) {
        for (auto& y: x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}