//성공
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    int N;
    cin >> N;
    
    multimap<int, string> m;
    for (int i = 0; i < N; i++) {
        int Ni;
        string name;
        cin >> Ni >> name;
        m.insert({Ni, name});
    }

    for (auto& x: m) {
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}