//왜 실패?
#include <iostream>
#include <string>
using namespace std;

int transPoint(string g) {
    if (g == "A+") return 450;
    else if (g == "A0") return 400;
    else if (g == "B+") return 350;
    else if (g == "B0") return 300;
    else if (g == "C+") return 250;
    else if (g == "C0") return 200;
    else if (g == "D+") return 150;
    else if (g == "D0") return 100;
    else if (g == "F") return 0;
}

string transRank(int i) {
    if (i > 450) return "impossible";
    else if (i == 450) return "A+";
    else if (i == 400) return "A0";
    else if (i == 350) return "B+";
    else if (i == 300) return "B0";
    else if (i == 250) return "C+";
    else if (i == 200) return "C0";
    else if (i == 150) return "D+";
    else if (i == 100) return "D0";
    else if (i == 0) return "F";
}




int Result(int sum, int sumofPoint, int i, int point) {
    int x = (sum + i * point) / sumofPoint;
    return x;
}

int main() {
    int N;
    string Xs;

    cin >> N >> Xs;
    Xs.erase(Xs.find('.'), 1);
    int X = stoi(Xs);

    int sum = 0;
    int sumofPoint = 0;

    int c;
    string g;
    for (int i = 0; i < N - 1; i++) {
        cin >> c >> g;
        sumofPoint += c;
        int gg = transPoint(g);
        sum += c * gg;
    }

    cin >> c;
    sumofPoint += c;

    for (int i = 0; ; i += 50) {
        if (Result(sum, sumofPoint, i, c) > X) {
            cout << transRank(i);
            break;
        }
    }

    return 0;
}