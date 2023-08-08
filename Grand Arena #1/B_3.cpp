//정답

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_ans(vector<string> list, string str, int q);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> list(N);
    for (auto &x: list) {
        cin >> x;
    }
    int q = find(list.begin(), list.end(), "?") - list.begin();

    int M;
    cin >> M;
    string str;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (is_ans(list, str, q)) {
            cout << str;
            break;
        }
    }

    return 0;
}

bool is_ans(vector<string> list, string str, int q) {
    if (find(list.begin(), list.end(), str) != list.end()) return false;
    if (q != 0) {
        if (list[q - 1].back() != str.front()) return false;
    }
    if (q != list.size() - 1) {
        if (list[q + 1].front() != str.back()) return false;
    }
    return true;    
}