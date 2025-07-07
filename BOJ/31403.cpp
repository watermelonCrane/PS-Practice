#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    cout << A + B - C << endl;
    string sA, sB;

    sA = to_string(A);
    sB = to_string(B);
    
    cout << stoi(sA + sB) - C;
    
    

    return 0;
}