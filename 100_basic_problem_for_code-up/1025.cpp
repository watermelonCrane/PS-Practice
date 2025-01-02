#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;

    vector<int> int_stack;
    for (int i = 10; a > 0; i *= 10) {
        int_stack.push_back(a % i);
        a -= int_stack.back();
    }

    for (; int_stack.empty() == false; int_stack.pop_back()) {
        cout << '[' << int_stack.back() << ']' << '\n';
    }

    return 0;
}