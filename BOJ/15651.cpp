//성공
//15649번과 비슷한듯 같은 N과 M 시리즈임
#include <iostream>
#include <vector>
using namespace std;

void NM(int N, int M, vector<int>& v) {
    if (v.size() == M) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= N; i++) {
            v.push_back(i);
            NM(N, M, v);
        }
    }
    v.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    
    NM(N, M, v);

    return 0;
}

/* #include <cstdio>
#include <vector>
using namespace std;

void NM(int N, int M, vector<int>& v) {
    int size = v.size();
    if (size == M) {
        for (int i = 0; i < size; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }   
    else {
        for (int i = 1; i <= N; i++) {
            v.push_back(i);
            NM(N, M, v);
        }
    }
    v.pop_back();
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> v;

    NM(N, M, v);

} */

