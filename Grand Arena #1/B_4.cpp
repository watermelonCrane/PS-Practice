//다른풀이. 
//정답.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool effectiveness(vector<string> v);

int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (auto &x: v) {
        cin >> x;
    }
    int q = find(v.begin(), v.end(), "?") - v.begin();

    int M;
    cin >> M;
    string tmp;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        if (find(v.begin(), v.end(), tmp) != v.end()) {
            continue;
        }
        v[q] = tmp;
        if (effectiveness(v)) {
            cout << tmp;
            break;
        }
    }


    return 0;
}

bool effectiveness(vector<string> v) {
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        if (v[i].back() != v[i + 1].front()) return false;
    }
    return true;
}