//실패
//왜????????

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Chess {
public:
    vector<pair<int, int>> yx;
    vector<pair<int, int>> banlist;
    int count = 0;
    int N;

    Chess(int N): N(N) {}

    bool isOK(int i, int k) {
        if (find(banlist.begin(), banlist.end(), make_pair(i, k)) == banlist.end()) return true;
        else return false;
    }

    int ban(int i, int k) {
        int bancount = 0;
        for (int a = 0; a < N; a++) {
            banlist.push_back(make_pair(i, a));
            banlist.push_back(make_pair(a, k));
            bancount += 2;
        }
        //오른쪽 아래로
        for (int a = i, b = k; a < N && b < N; a++, b++) {
            banlist.push_back(make_pair(a, b));
            bancount++;
        }
        //왼쪽 위로
        for (int a = i, b = k; a >= 0 && b >= 0; a--, b--) {
            banlist.push_back(make_pair(a, b));
            bancount++;
        }
        //왼쪽 아래로
        for (int a = i, b = k; a < N && b >= 0; a++, b--) {
            banlist.push_back(make_pair(a, b));
            bancount++;
        }
        //오른쪽 위로
        for (int a = i, b = k; a >= 0 && b < N; a--, b++) {
            banlist.push_back(make_pair(a, b));
            bancount++;
        }
        
        return bancount;
    }
    void unban(int bancount) {
        for (int i = 0; i < bancount; i++) {
            banlist.pop_back();
        }
    }
    void hold(int i, int k) {
        yx.push_back(make_pair(i, k));
    }
    void unhold() {
        yx.pop_back();
    }


    void Queen(int a, int b) {
        if (yx.size() == N) {
            count++;
            return;
        }
        for (int i = a; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (i <= a && k <= b) continue;
                if (isOK(i, k)) {
                    hold(i, k);
                    int bancount = ban(i, k);

                    Queen(i, k);

                    unban(bancount);
                    unhold();
                }
            }
        }

    }
    
};

int main() {
    int N;
    cin >> N;

    Chess chess(N);

    chess.Queen(0, 0);

    cout << chess.count;

    return 0;
}