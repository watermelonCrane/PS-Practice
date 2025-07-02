#include <iostream>
#include <vector>
using namespace std;

class Maze {
public:
    vector<vector<int>> maze;

    Maze() {
        maze.resize(10, vector<int>(10));
    }

    void inputMaze() {
        for (auto& x: maze) {
            for (auto& y: x) {
                cin >> y;
            }
        }
    }

    void printMaze() {
        for (auto& x: maze) {
            for (auto& y: x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    }

};

class Ant {
public:
    pair<int, int> position;

    Ant() {
        position = make_pair(1, 1);
    }
    
    void goRight() {
        position.second++;
    }

    void goDown() {
        position.first++;
    }

};

class Game {
public:

    bool canGoRight(Ant& p, Maze& m) {
        if (m.maze[p.position.first][p.position.second + 1] != 1) {
            return true;
        } else {
            return false;
        }
    }

    bool canGoDown(Ant& p, Maze& m) {   // false면 걍 게임 끝난거임
        if (m.maze[p.position.first + 1][p.position.second] != 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isClear(Ant& p, Maze& m) {
        if (m.maze[p.position.first][p.position.second] == 2){
            return true;
        } else {
            return false;
        }
    }

    void fillPath(Maze& m, int x, int y) {
        m.maze[x][y] = 9;
    }

};

int main() {
    Ant p;
    Maze m;
    Game game;

    m.inputMaze();

    while (1) {
        if (game.isClear(p, m)) {
            game.fillPath(m, p.position.first, p.position.second);
            break;
        }

        game.fillPath(m, p.position.first, p.position.second);

        if (game.canGoRight(p, m)) {
            p.goRight();
            continue;
        } else {
            if (game.canGoDown(p, m)) {
                p.goDown();
                continue;
            } else {
                break;
            }
        }

    }

    m.printMaze();

    return 0;
}