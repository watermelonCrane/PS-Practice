//왜 연산자 < 만 오버로딩 했을때는 정렬이 의도한 대로 안되고, 연산자를 오버로딩 한 후에 compare로 sort에 전달하면 의도한대로 정렬이 되는거지??? 모르겠다....
//왜 이게 더 속도가 빠르지?????
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool operator+(string& str1, string& str2) {
    if (str1.size() == str2.size()) return str1 < str2;
    else return str1.size() < str2.size();
}

bool compare(string& str1, string& str2) {
    return str1 + str2;
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

    for (int i = 0; i < N; i++) {
        if (i != 0 && v[i] == v[i - 1]) continue;
        cout << v[i] << '\n';
    }

    return 0;
}