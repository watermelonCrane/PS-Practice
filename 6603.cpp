//성공
#include <iostream>
#include <vector>
using namespace std;

void lotto(int k, vector<int>& S, vector<int>& result) {
    if (result.size() == 6) {
        for (auto& x : result) {
            cout << S[x] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < k; i++) {
            if (!result.empty() && result.back() >= i) continue;
            result.push_back(i);
            lotto(k, S, result);
        }
    }
    result.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1) {
        int k;
        cin >> k;
        if (k == 0) break;

        vector<int> S(k);
        for (int i = 0; i < k; i++) {
            cin >> S[i];
        }

        vector<int> result;
        lotto(k, S, result);
        cout << "\n";
    }

    return 0;
}