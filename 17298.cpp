//성공이긴 한데..
//혼자힘을 풀지 못했음. 풀이를 보고 아이디어를 얻어서 풀었다.
//조금 아쉽다. 더 잘 풀 수 있었을 텐데..
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> stack;
    vector<int> NGE(N);

    for (auto& x: A) {
        cin >> x;
    }

    for (int i = N - 1; i >= 0; i--) {
        while (!stack.empty()) {
            if (A[i] < stack.back()) {
                NGE[i] = stack.back();
                break;
            }
            else {
                stack.pop_back();
            }
        }
        if (stack.empty()) {
            NGE[i] = -1;
        }
        stack.push_back(A[i]);
    }

    for (auto& x: NGE) {
        cout << x << ' ';
    }


    return 0;
}