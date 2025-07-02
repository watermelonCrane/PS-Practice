//일단 맞춤
//코드를 바로 짜기보다는 설계를 하고 짜자
//아직 100퍼센트 이해가 되지 않은 느낌이다. 다시 복습해보자.
//아래링크를 참고해서 풀었었다. 카운트를 하는 방법은 점화식을 만드는 것이다.
//재귀는 점화식이다.
//수학적으로 푸는 것이 가능하다.
//문제를 작은단위부터 해보고, 일반화를 하자. 
//https://shoark7.github.io/programming/algorithm/tower-of-hanoi

#include <iostream>
using namespace std;

void move(const int start, const int to) {
    cout << start << " " << to << "\n";
}

void printTop(int N, const int start, const int to, const int via) {
    if (N != 1) {
        printTop(N - 1, start, via, to);
        move(start, to);
        printTop(N - 1, via, to, start);

    }
    else {
        move(start, to);
    }
}

int main() {
    int N;
    cin >> N;
    cout << (1 << N) - 1 << "\n";   //비트연산이 더 빠름

    printTop(N, 1, 3, 2);

    return 0;
}