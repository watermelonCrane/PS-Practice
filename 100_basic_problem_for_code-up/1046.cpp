#include <iostream>
#include <iomanip>

int main() {

    int a, b, c;
    long long sum;
    double average;
    std::cin >> a >> b >> c;

    sum = a + b + c;
    average = static_cast<double>(sum) / 3.0f;

    std::cout << sum << std::endl << std::fixed << std::setprecision(1) << average;

    return 0;
}