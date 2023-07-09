#include <cstdio>
#include <vector>

bool operator<(std::pair<int, int>& p1, std::pair<int, int>& p2) {
    return p1.first < p2.first && p1.second < p2.second;
}


int main() {
    std::vector<std::pair<int, int>> ppl;
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        std::pair<int, int> tmp;
        scanf("%d %d", &tmp.first, &tmp.second);
        ppl.push_back(tmp);
    }

    return 0;
}