//성공
#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    
    for (int i = 1; i <= T; i++) {
        int rank;
        scanf("%d", &rank);
        if (rank > 4500) {
            char round[] = "Round 1";
            printf("Case #%d: %s\n", i, round);
        }
        else if (rank > 1000) {
            char round[] = "Round 2";
            printf("Case #%d: %s\n", i, round);
        }
        else if (rank > 25) {
            char round[] = "Round 3";
            printf("Case #%d: %s\n", i, round);
        }
        else {
            char round[] = "World Finals";
            printf("Case #%d: %s\n", i, round);
        }
    }


    return 0;
}