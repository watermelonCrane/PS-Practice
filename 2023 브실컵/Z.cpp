//성공
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string gong = "Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna stop";
    
    int N;
    cin >> N;
    cin.ignore();

    string tmp;
    for (int i = 0; i < N; i++) {
        getline(cin, tmp);
        if (gong.find(tmp) == string::npos) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    return 0;
}