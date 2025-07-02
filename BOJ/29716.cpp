//성공
#include <cstdio>

int main() {
    int J, N;
    scanf("%d %d", &J, &N);

    char tmp[100];
    int size = 0;
    int result = 0;
    for (int i = 0; i < N; i++) {
        size = 0;
        scanf(" %[^\n]s", tmp);
        for (int i = 0; tmp[i] != '\0'; i++) {
            if (tmp[i] >= 65 && tmp[i] <= 90) {
                size += 4;
            }
            else if (tmp[i] == ' ') {
                size += 1;
            }
            else {
                size += 2;
            }
        }
        if (size <= J) {
            result++;
        }
    }

    printf("%d", result);

    return 0;
}