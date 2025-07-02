#include <iostream>
using namespace std;

int main() {
    long long w, h, b;
    cin >> w >> h >> b;
    double result = w * h * b / 8.0f / 1024.0f / 1024.0f;
    cout << fixed;
    cout.precision(2);
    cout << result << " MB";

    return 0;
}