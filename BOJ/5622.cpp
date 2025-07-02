//성공
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string number;
    string::iterator it;
    cin >> number;

    vector<string> dic(10);
    dic[2] = "ABC";
    dic[3] = "DEF";
    dic[4] = "GHI";
    dic[5] = "JKL";
    dic[6] = "MNO";
    dic[7] = "PQRS";
    dic[8] = "TUV";
    dic[9] = "WXYZ";

    int time = 0;
    for (it = number.begin(); it < number.end(); it++) {
        for (int i = 2; i < 10; i++) {
            if (dic[i].find(*it) != string::npos) {
                time += i + 1;
            }
        }
    }
    
    cout << time;

    return 0;
}