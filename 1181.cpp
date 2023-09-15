//성공 ver1...

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string str1, string str2) {
    if (str1.size() == str2.size()) {
        return str1 < str2;
    }
    else {
        return str1.size() < str2.size();
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<string> v(N);
    for (auto& x: v) {
        cin >> x;
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        if (i != 0 && v[i] == v[i - 1]) continue;
        cout << v[i] << '\n';
    }


    return 0;
}