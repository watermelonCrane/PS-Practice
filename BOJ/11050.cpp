#include <iostream>
using namespace std;

int combi(int N, int K) {
    int RN = 1;
    for (int i = 0; i < K; i++) {
        RN *= N;
        N--;
    }

    int KFac = 1;
    for (; K; ) {
        KFac *= K;
        K--;
    }

    return RN / KFac; 
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << combi(N, K);


    return 0;
}