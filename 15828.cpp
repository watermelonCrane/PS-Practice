//성공
#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;;
    cin >> N;

    queue<int> q;
    int tmp;
    while (1) {
        cin >> tmp;
        if (tmp == -1) break;
        if (tmp == 0) q.pop();
        else if (q.size() == N) continue;
        else q.push(tmp);
    }

    if (q.size() == 0) {
        cout << "empty";
    }
    else {
        while (q.size()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }

    return 0;
}