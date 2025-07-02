#include <iostream>
#include <iomanip>

int main() {

    long long a, b;
    using namespace std;
    cin >> a >> b;
    cout << a + b << endl << a - b << endl << a * b << endl << a / b << endl << a % b << endl << fixed << setprecision(2) << static_cast<double>(a) / static_cast<double>(b);

    return 0;
}