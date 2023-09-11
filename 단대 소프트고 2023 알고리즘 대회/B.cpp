//모르겠다....
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CCLLS {
public:
    int index;
    int score;
    int rcore;
    int bangmoon = 0;
    CCLLS(int index, int score, int rcore) : index(index), score(score), rcore(rcore) {};

    bool operator>(CCLLS& newclss) {
        return rcore > newclss.rcore;
    }
};

bool compare(CCLLS a, CCLLS b) {
    return a.rcore > b.rcore;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<CCLLS> ccllss;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) ccllss.push_back(CCLLS(i, tmp, tmp));
        else ccllss.push_back(CCLLS(i, tmp, ccllss.back().rcore + tmp));
    }

    vector<CCLLS> recls;
    for (auto& x: ccllss) {
        recls.push_back(x);
    }

    sort(recls.begin(), recls.end(), compare);

    vector<int> Kbangmoon(K);
    for (int i = 0; i < K; i++) {
        Kbangmoon[i] = recls[i].index;
    }

    for (int i = 0; i < K; i++) {
        for (int k = 0; k < Kbangmoon[i]; k++) {
            ccllss[k].bangmoon++;
        }
    }

    int result = 0;
    for (auto& x: ccllss) {
        result += x.score * x.bangmoon;
    }

    cout << result;
    
    return 0;
}