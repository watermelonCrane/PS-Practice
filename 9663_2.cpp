//시발 ㅋㅋㅋㅋㅋㅋ 이게 시간초과가 안뜨고 성공하네
// 시간 초과 안뜨고 성공!!
// 그 전 시도는 원리를 이해 하지 않았다고 생각한다.
// https://cru6548.tistory.com/8 여기서 본질을 파악하란 아이디어를 얻었다.
// 어차피 가로에 1개, 세로에 1개들어갈테니
// 한줄에 채워 넣었으면, 다음 줄 부터 생각하면 되고, 그 세로줄에 뭐 하나라도 있으면, 안되고,
// 그걸 체크하는게 vertban벡터고, ***1 주석이다.
// 모범답안을 찾아서 내 코드와 비교해보도록 하자.
// 시간복잡도는 어떻게 되냐?
// 내일 해야지
#include <iostream>
#include <vector>
using namespace std;

bool isOK(int i, int k, vector<pair<int, int>> & hold) {
    for (auto& x: hold) {
        if (x.first - i == x.second - k || i - x.first == x.second - k) return false;
    }
    return true;
}

int NQ(int N) {
    int count = 0;

    vector<pair<int, int>> hold;
    vector<bool> vertban(N, true);

    int i = 0;
    int k = 0;
    while (1) {
        for (; i < N && k < N; i++) {
            for (; k < N; k++) {
                if (!hold.empty()) {
                    if (!vertban[k]) continue;
                    if (!isOK(i, k, hold)) continue;
                }
                hold.push_back({i, k});
                vertban[k] = false;
                if (i < N - 1) {            // ***1
                    i++;
                    k = -1;
                }
                if (hold.size() == N) {
                    count++;
                    i = N;
                    break;
                }
            }
        }

        if (hold.back().second == N - 1) {
            vertban[hold.back().second] = true;
            hold.pop_back();
        }
        //for (; !hold.empty() && hold.back().second == N - 1; hold.pop_back());
        if (hold.empty()) break;
        i = hold.back().first;
        k = hold.back().second + 1;
        vertban[hold.back().second] = true;
        hold.pop_back();
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