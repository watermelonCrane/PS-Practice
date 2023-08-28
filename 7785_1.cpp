//성공
//map을 이용한 RBTree를 이용해서 풀었다.
//해시테이블을 이용하는 방법도 있다.
//시간을 줄이는 방법

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    map<string, string, greater<string>> log;
    map<string, string>::iterator it;

    int n;
    cin >> n;
    while (n--) {
        string str;
        string enter;
        cin >> str >> enter;
        log[str] = enter;       //없는 인덱스는 새로 만들어서 추가된다.***
    }

    for (auto& x : log) {
        if (x.second == "enter") {
            cout << x.first << "\n";
        }
    }

    return 0;
}