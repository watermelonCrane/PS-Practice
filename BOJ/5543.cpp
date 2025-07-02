//성공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> buger(3);
    int cola;
    int cidar;
    for (auto& x: buger) {
        cin >> x;
    }
    cin >> cola;
    cin >> cidar;

    cout << *min_element(buger.begin(), buger.end()) + min(cola, cidar) - 50;

    return 0;
}