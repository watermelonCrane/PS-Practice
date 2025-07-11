#include <iostream>
using namespace std;

int findGCF(int a, int b) {
    //생각해보니까 좀 비효율적인데
    int result;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) result = i;
    }

    return result;
}

int findLCM(int a, int b) {
    int GCF = findGCF(a, b);
    a = a / GCF;
    b = b / GCF;
    return GCF * a * b;

}

int findLCM(int a, int b, int GCF) {
    a = a / GCF;
    b = b / GCF;
    return GCF * a * b;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    cout << findGCF(a, b) << '\n';
    cout << findLCM(a, b);


    return 0;
}