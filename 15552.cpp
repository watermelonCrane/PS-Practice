//빠른 입출력 ver1

#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    int a, b;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}