#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x: v) {
        cin >> x;
    }

    cout << *(min_element(v.begin(), v.end()));
    
    return 0;
}