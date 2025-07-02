//성공, 많은분기 문제 같은데.. 나중에 풀이를 보고 싶다.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& x: v) {
        cin >> x;
    }

    int max = 0;
    bool frize = true;
    int frizeCount = 0;

    int count = 0;
    for (auto& x: v) {
        if (frizeCount == 2) {
            frizeCount = 0;
            frize = true;
        }
        if (x == 0) {
            if (frize) {
                frize = false;
            }
            else {
                count = 0;
            }
        }
        else {
            count++;
        }
        if (!frize) {
            frizeCount++;
        }
        if (max < count) max = count;

    }

    cout << max;

    return 0;
}