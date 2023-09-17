#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M, K, S;
    
    cin >> N;
    vector<char> Ns(N);
    for (auto& x: Ns) {
        cin >> x;
    }

    cin >> M;
    vector<char> Ms(M);
    for (auto& x: Ms) {
        cin >> x;
    }

    cin >> K;
    vector<char> Ks(K);
    for (auto& x: Ks) {
        cin >> x;
    }

    cin >> S;

    string str;
    cin.ignore();
    getline(cin, str);
    
    bool enter = false;
    for (auto x = str.begin(); x < str.end(); x++) {
        if (find(Ks.begin(), Ks.end(), *x) != Ks.end() || ((find(Ns.begin(), Ns.end(), *x) == Ns.end()) && (find(Ms.begin(), Ms.end(), *x) == Ms.end()) && *x != ' ')) {
            cout << *x;
            enter = true;
        }
        else {
            if (enter) {
                cout << '\n';
                enter = false;
            }
        }
    }



    return 0;
}