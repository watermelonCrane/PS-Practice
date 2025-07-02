#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    string str;
    cin >> N >> str;
    int sum = 0;
    for (auto x : str) {
        sum += x - 48;
    }
    cout << sum;
}