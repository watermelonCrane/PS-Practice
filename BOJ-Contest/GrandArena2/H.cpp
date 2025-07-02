//생각하기를 포기함


#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool correct(string str) {
    vector<char> stack;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (str[i] == '(') stack.push_back('(');
        else if (str[i] == ')') {
            if (str[i - 1] != '(') return false;
            stack.pop_back();
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    string str;
    for (int i = 0; i < T; i++) {
        cin >> str;
        if (correct(str)) {
            cout << "YES\n";
            continue;
        }
        else {

        }
        
    }

    

    return 0;
}