#include <cstdio>
#include <cstring>

int main() {
    int T;
    scanf("%d", &T);

    char str[1001];
    

    for (int i = 0; i < T; i++) {
        scanf("%s", str);
        printf("%c", str[0]);
        printf("%c\n", str[strlen(str) - 1]);

    }

    return 0;
}