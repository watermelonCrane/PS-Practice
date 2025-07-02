#include <cstdio>
#include <vector>
#include <algorithm>

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N;
    scanf("%d", &N);
    std::vector<int> score;

    for (int i = 0; i < N; i++) {
        int run[2];
        int trick[5];
        for (int k = 0; k < 2; k++) {
            scanf("%d", &run[k]);
        }
        for (int k = 0; k < 5; k++) {
            scanf("%d", &trick[k]);
        }
        std::sort(run, run + 2, compare);
        std::sort(trick, trick + 5, compare);
        
        score.push_back(run[0] + trick[0] + trick[1]);
    }
    std::sort(score.begin(), score.end(), compare);
    printf("%d", score.front());


    return 0;
}