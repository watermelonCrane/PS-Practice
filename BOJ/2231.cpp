//성공
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int result = 0;
    string::iterator it;
    for (int i = 1; i <= N; i++) {
        int M = i;
        string sM = to_string(M);
        for (it = sM.begin(); it < sM.end(); it++) {
            int tmp;
            tmp = static_cast<int>(*it) - 48;
            M += tmp;
            if (M > N) {    //최적화
                break;
            }
        }
        if (M == N) {
            result = i;
            break;
        }
    }

    cout << result;
    

    return 0;
}