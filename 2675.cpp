#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);

    int R;
    char S[21];

    for (int i = 0; i < T; i++) {       //for문 줄이기 귀찮음...
        scanf("%d %s", &R, S);
        for (int k = 0; S[k] != '\0'; k++) {
            for (int p = 0; p < R; p++) {   //삼중 반복문 레전드네, 변수 k 다음에 뭐 써야하냐...
                printf("%c", S[k]);
            }
        }
        printf("\n");
    }

    return 0;
}