//성공
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }

    queue<int> printQ;
    for (int i = 0; q.size(); i++) {
        i %= K;
        if (i == K - 1) {
            printQ.push(q.front());
            q.pop();
            continue;
        }
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << '<';
        }
        cout << printQ.front();
        printQ.pop();
        if (i != N - 1) {
            cout << ", ";
        }
        else {
            cout << '>';
        }
    }

    return 0;
}