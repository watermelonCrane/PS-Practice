//모기가 너무 많아 ㅠㅠ
#include <iostream>
using namespace std;

int main() {
    int mode = 0;   // 1: ascending, -1: decending, 0: mixed or TBC 

    int previous;
    cin >> previous;

    for (int i = 0; i < 7; i++) {
        int name;
        cin >> name;
        if (mode == 0) {        //mode set;
            if (name == previous + 1) mode = 1;
            else if (name == previous - 1) mode  = -1;
            else break;
        }
        else if (mode == 1) {
            if (name != previous + 1) {
                mode = 0;
                break;
            }
        }
        else if (mode == -1) {
            if (name != previous - 1) {
                mode = 0;
                break;
            }
        }
        previous = name;
    }

    // print result
    if (mode == 0) cout << "mixed";
    else if (mode == 1 ) cout << "ascending";
    else if (mode == -1) cout << "descending";

    return 0;
}