//정답이긴 한데, 이렇게 푸는 방법 말고 더 빠른 시간으로 푸는 방법이 있을 거다.
//다른 풀이를 살펴보도록 하자.
#include <iostream>
#include <vector>
using namespace std;

int sumV(vector<int>& index, vector<int>& seq) {
    int sum = 0;
    for (auto& x: index) {
        sum += seq[x];
    }
    return sum;
}

void NM(vector<int>& index, vector<int>& seq, int N, int M, int& count, const int& S) {
    if (index.size() == M) {
        if (sumV(index, seq) == S) {
            count++;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (!index.empty() && index.back() <= i) continue;
            index.push_back(i);
            NM(index, seq, N, M, count, S);
        }
    }
    if (!index.empty()) {
        index.pop_back();
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    vector<int> seq(N);
    for (auto& x: seq) {
        cin >> x;
    }

    vector<int> index;
    int count = 0;

    for (int i = 1; i <= N; i++) {
        NM(index, seq, N, i, count, S);
    }

    cout << count;

    return 0;
}