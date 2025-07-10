#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
const char* WRONG = "wrong\n";
const char* RIGHT = "right\n";

vector<int> makeTriangle() {
    vector<int> tri(3);
    for (int& x: tri) {
        cin >> x;
    }

    sort(tri.begin(), tri.end());

    return tri;
}

int isRight(const vector<int>& tri) {
    if (tri[0] == 0) return 0;

    int a = pow(tri[0], 2);
    int b = pow(tri[1], 2);
    int c = pow(tri[2], 2);
    if (c == a + b) return 1;
    else return -1;
}

int main() {

    for (;;) {
        // vector<int> v = makeTriangle();
        int what = isRight(makeTriangle());
        if (what) {
            if (what == 1) cout << RIGHT;
            else if (what == -1) cout << WRONG;
        } else break;;
    }
    
    return 0;
}