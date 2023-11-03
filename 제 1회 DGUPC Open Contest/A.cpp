//성공
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;

    while (N--) {
        int a, b;
        cin >> a >> b;
        v.push_back(b);
    }

    int maxY, minY;
    maxY = *max_element(v.begin(),v.end());
    minY = *min_element(v.begin(), v.end());

    cout << maxY - minY;


}