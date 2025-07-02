//시간초과
//어떻게 최적화?
#include <iostream>
#include <vector>
using namespace std;

bool isOK(int i, int k, vector<pair<int, int>>& hold) {
    for (auto& x: hold) {
        if (x.second == k) return false;    //세로로 같으면
        if (x.first == i) return false;     //가로로 같으면;
        if (abs(x.first - i) == abs(x.second - k)) return false;  //대각선으로 같을 때
    }
    return true;
}

int NQ(int N) {
    vector<pair<int, int>> hold;
    int count = 0;

    int i = 0;
    int k = 0;
    bool isloop = true;
    while(isloop) {
        for (; i < N; i++) {
            for (; k < N; k++) {
                if (isOK(i, k, hold)) {
                    hold.push_back({i, k});
                    if (i < N - 1) i++;
                    k = -1;
                    if (hold.size() == N) {
                        count++;
                        break;
                    }
                }                
            }

            if (hold.size() == N) {
                break;
            }
            k = 0;
        }

        for (;;) {
            if (hold.size() == 1 && hold.back().first == N - 1 && hold.back().second == N - 1) {
                isloop = false;
            }
            if (hold.back().first < N - 1) {
                if (hold.back().second < N - 1) {
                    i = hold.back().first;
                    k = hold.back().second + 1;
                }
                else {
                    i = hold.back().first + 1;
                    k = 0;
                }
                hold.pop_back();
                break;
            }
            else if (hold.back().second < N - 1) {
                i = hold.back().first;
                k = hold.back().second + 1;
                hold.pop_back();
                break;
            }
            else {
                hold.pop_back();
            }
        }
    }

    return count;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    cout << NQ(N);

    return 0;
}