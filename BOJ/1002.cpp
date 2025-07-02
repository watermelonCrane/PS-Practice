//조건이 너무 많고
//이 조건을 생각하는게 힘들고
//조건을 정리하는 것이 힘듬
//힌트를 찾으면서 풀어서 성공하긴 했지만
//좀 힘들었다. 나중에 다시 정리해보자.

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    

    pair<int, int> Jo, Back;
    int r1, r2;
    while (T--) {
        cin >> Jo.first >> Jo.second >> r1 >> Back.first >> Back.second >> r2;
        double d = sqrt(pow((Jo.first - Back.first), 2) + pow((Jo.second - Back.second), 2));
        int dr = r1 > r2 ? r1 - r2 : r2 - r1;

        if (d == 0 && r1 == r2) {
            cout << "-1\n";
            continue;
        }
        if (d < r1 + r2) {
            if (dr < d) {
                cout << "2\n";
                continue;
            }
        }
        if (d == r1 + r2 || d == dr) {
            cout << "1\n";
            continue;
        }

        cout << "0\n";


    }
    return 0;
}