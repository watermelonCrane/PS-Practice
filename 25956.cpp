//성공은 했지만
//야만적임
//자료구조를 이용해서 풀어보자
#include <iostream>
#include <vector>
using namespace std;

bool isOk(vector<int>& list) {
    if (list[0] != 1) return false;
    for (int i = 1; i < list.size(); i++) {
        if (list[i] > list[i - 1] + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> list(N);
    for (auto& x: list) {
        cin >> x;
    }

    if (!isOk(list)) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int k = i + 1; k < N; k++) {
            if (list[k] <= list[i]) break;
            if (list[k] == list[i] + 1) {
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}