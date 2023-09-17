//성공
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ink {
public:
    string ink;
    int power = 0;
};

class Player {
public:
    pair<int, int> pos;
    Ink ink;
    string::iterator nowInk;

    void initInk() {
        nowInk = ink.ink.begin();
    }

    void changeInk() {
        nowInk++;
        if (nowInk == ink.ink.end()) {
            initInk();
        }
    }

    void chargeInk() {
        ink.power++;
    }
};

class Stage {
public:
    vector<vector<char>> stage;
    string cmd;

    Player p;


    void makeStage(int N) {
        for (int i = 0; i < N; i++) {
            stage.push_back(vector<char>());
            for (int k = 0; k < N; k++) {
                char tmp;
                cin >> tmp;
                if (tmp == '@') {
                    p.pos = {i, k};
                }
                stage.back().push_back(tmp);
            }
        }
    }

    void inputCommand() {
        cin >> cmd;
    }

    void doCommand(char c) {
        pair<int, int> toPos = p.pos;
        if (c == 'U') {
            toPos.first--;
        }
        else if (c == 'D') {
            toPos.first++;
        }
        else if (c == 'L') {
            toPos.second--;
        }
        else if (c == 'R') {
            toPos.second++;
        }
        else if (c == 'j') {
            p.chargeInk();
        }
        else if (c == 'J') {
            splash();
            p.changeInk();
            p.ink.power = 0;
        }
        if (!moveAble(toPos.first, toPos.second)) return;
        else {
            stage[p.pos.first][p.pos.second] = '.';
            p.pos = toPos;
            stage[p.pos.first][p.pos.second] = '@';
        }
    }

    bool moveAble(int y, int x) {
        if (y < stage.size() && y >= 0) {
            if (x < stage[y].size() && x >= 0) {
                if (stage[y][x] != '@' && stage[y][x] != '.') return false;
                return true;
            }
        }
        return false;
    }
    
    bool isBlock(int y, int x) {
        char tmp = stage[y][x];
        if (tmp != '@' && tmp != '.') {
            return true;
        }
        return false;
    }

    bool paintAble(int a, int b) {
        if (abs(p.pos.first - a) + abs(p.pos.second - b) <= p.ink.power) {
            return true;
        }
        return false;
    }

    void paint(int y, int x) {
        stage[y][x] = *p.nowInk;
    }

    void splash() {
        for (int y = 0; y < stage.size(); y++) {
            for (int x = 0; x < stage[y].size(); x++) {
                if (isBlock(y, x)) {
                    if (paintAble(y, x)) {
                        paint(y, x);
                    }
                }
            }
        }

    }

    void printStage() {
        for (auto& y: stage) {
            for (auto& x: y) {
                cout << x;
            }
            cout << '\n';
        }
    }

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int I, N, K;
    cin >> I >> N >> K;

    Stage s;
    cin >> s.p.ink.ink;

    s.makeStage(N);
    s.inputCommand();
    s.p.initInk();

    for (auto it = s.cmd.begin(); it != s.cmd.end(); it++) {
        s.doCommand(*it);
    }

    s.printStage();



    return 0;
}