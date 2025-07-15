// 틀렸습니다!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& Ns, int data, int low, int mid, int high) {
    if (low > mid || mid > high) return -100;
    
    if (Ns[mid] == data) return mid;
    else if (data < Ns[mid]) {
        return binarySearch(Ns, data, low, mid / 2, mid - 1);
    }
    else {
        return binarySearch(Ns, data, mid + 1, mid + (high - mid) / 2 + 1, high);
    }

    
}

int main() {
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
        int data;
        cin >> data;

        int exist = binarySearch(Ns, data, 0, N / 2, N - 1);

        if (exist >= 0) cout << '1';
        else cout << '0';



        cout << '\n';
    }
    




    return 0;
}