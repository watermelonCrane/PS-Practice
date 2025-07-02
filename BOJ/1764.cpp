//정답
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    
    map<string, bool, less<string>> m;
    map<string, bool>::iterator it;
    string str;
    while (N--) {
        cin >> str;
        m[str] = false;
    }
    while (M--) {
        cin >> str;
        it = m.find(str);
        if (it != m.end()) {
            it->second = true;
        }
    }

    vector<string> list;
    int su = 0;
    for (auto& x : m) {
        if (x.second) {
            su++;
            list.push_back(x.first);
        }
    }
    cout << su << "\n";
    for (auto& x : list) {
        cout << x << "\n";
    }

    return 0;
}