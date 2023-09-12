//성공
#include <iostream>
using namespace std;

int judgeChess(char C) {
    switch(C) {
        case '.': return 0;
        case 'K': return 0;
        case 'P': return 1;
        case 'N': return 3;
        case 'B': return 3;
        case 'R': return 5;
        case 'Q': return 9;

        case 'k': return 0;
        case 'p': return -1;
        case 'n': return -3;
        case 'b': return -3;
        case 'r': return -5;
        case 'q': return -9;   
    }
}

int main() {
    int score = 0;
    
    for (int i = 0; i < 64; i++) {
        char tmp;
        cin >> tmp;
        score += judgeChess(tmp);
    }

    cout << score;

    return 0;
}