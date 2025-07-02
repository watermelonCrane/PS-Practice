//성공
//여기서 간과한 사실. 연산자 오버로딩만으로는 기본 stl의 자료형을 의도대로 정렬할 수 없다.
//여기서 이것이 정답처리 된 것은, 기본 pair가 문제에서 요구하는대로 정렬하는 기능이 있기 때문, 비교연산이 가능했기 때문이다.
//따라서.
//주석처리를 한 채로도 정답이 나올 것이다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool operator<(pair<int, int> a, pair<int, int> b) {
//     if (a.first == b.first) return a.second < b.second;
//     else return a.first < b.first;
// }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (auto& x: v) {
        cin >> x.first >> x.second;
    }

    sort(v.begin(), v.end());

    for (auto& x: v) {
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}