//실패


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    //기록 제공
    int N, QM;
    string tmp;
    vector<string> log;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        log.push_back(tmp);
        if (tmp == "?") {
            QM = i;
        }    
    }

    if (QM != 0 && QM != N - 1) {
        pair<char, char> lastfirst;
        lastfirst.first = log[QM -1].back();
        lastfirst.second = log[QM + 1].front();


        //후보단어 제공
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> tmp;
            if (tmp.front() == lastfirst.first && tmp.back() == lastfirst.second) {
                if (find(log.begin(), log.end(), tmp) == log.end()) {
                    cout << tmp;
                }
            }
        }
    }
    else if (QM != 0) {

        char last = log[QM - 1].back();

        //후보단어 제공
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> tmp;
            if (tmp.front() == last) {
                if (find(log.begin(), log.end(), tmp) == log.end()) {
                    cout << tmp;
                }
            }
        }
    }
    else if (QM != N - 1) {
        char first = log[QM + 1].front();
        
        //후보단어 제공
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> tmp;
            if (tmp.back() == first) {
                if (find(log.begin(), log.end(), tmp) == log.end()) {
                    cout << tmp;
                }
            }
        }
    }

    return 0;
}