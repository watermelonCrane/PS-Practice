//성공
//문제의 []를 사용한다는게 잘 이해가 안갔는데, BT라는 점을 생각하고, 괄호 양쪽이 가지라고 같은 쌍인 가지라고 생각해보자. 그리고 이 그림도 참고해보자. https://deveun.tistory.com/entry/Python%EB%B0%B1%EC%A4%80-2716%EC%9B%90%EC%88%AD%EC%9D%B4-%EB%A7%A4%EB%8B%AC%EA%B8%B0
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
        string dungool;
        getline(cin, dungool);
        int maxD = 0;
        int depth = 0;
        for (auto it = dungool.begin(); it != dungool.end(); it++) {
            if (*it == '[') depth++;
            else depth--;
            if (maxD < depth) maxD = depth;
        }
        int result = pow(2, maxD);
        cout << result << '\n';
    }

    return 0;
}