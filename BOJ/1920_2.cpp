#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& Ns, int data, int start, int end) {
    if (start > end) return -100;

    int mid = (start + end) / 2;

    if (Ns[mid] == data) return mid;
    else if (data < Ns[mid]) return find(Ns, data, start, mid - 1);
    else return find(Ns, data, mid + 1, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N;
    cin >> N;
    vector<int> Ns(N);
    for (auto& x: Ns) {
        cin >> x;
    }

    sort(Ns.begin(), Ns.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (find(Ns, tmp, 0, N - 1) >= 0) cout << '1';
        else cout << '0';
        cout << '\n';
    }



    return 0;
}