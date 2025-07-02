//성공
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    list<int> l(N);
    for (auto& x: l) {
        cin >> x;
    }

    l.sort();
    int count = 0;
    for (auto it = l.begin(); it != l.end(); it++) {
        if (it == l.begin()) {
            count++;
            continue;
        }
        
        auto it2 = it;
        it2--;
        it2--;
        if (*it == *it2) continue;
        else count++;

    }

    cout << count;

    return 0;
}