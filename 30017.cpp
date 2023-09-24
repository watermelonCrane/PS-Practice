//성공
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<int> buger;
    bool pandan = 1;

    while (A && B) {
        if (pandan) {
            A--;
            buger.push_back(1);
            pandan = 0;
        }
        else {
            B--;
            buger.push_back(0);
            pandan = 1;
        }
    }
    if (buger.back() == 0) {
        if (A) {
            buger.push_back(1);
        }
        else {
            buger.pop_back();
        }        
    }

    cout << buger.size();

    return 0;
}