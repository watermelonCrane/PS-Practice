#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int BUCKET_SIZE = 1024;

vector<int> buckets[BUCKET_SIZE];
bool isSorted[BUCKET_SIZE] = {false};

int getBucketIndex(int num) {
    const int OFFSET = 10000000;
    const int SIZE = 20000;

    int adjustNumber = num + OFFSET;
    int index = adjustNumber / SIZE;

    if (index >= BUCKET_SIZE) {
        return BUCKET_SIZE - 1;
    }
    return index;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        int index = getBucketIndex(tmp);
        buckets[index].push_back(tmp);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        int index = getBucketIndex(tmp);

        if (!isSorted[index]) {
            sort(buckets[index].begin(), buckets[index].end());
            isSorted[index] = true;
        }

        auto range = equal_range(buckets[index].begin(), buckets[index].end(), tmp);
        cout << distance(range.first, range.second) << ' ';
    }
    


    return 0;
}