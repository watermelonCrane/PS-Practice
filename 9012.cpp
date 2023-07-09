//230507

#include <cstdio>
#include <cstring>

int main() {

    int T;
    scanf("%d", &T);
    char VPS[52];

    for (int i = 0; i < T; i++) {
        scanf("%s", VPS);
        int judge = 0;
        for (int i = strlen(VPS); i; i--) {
            if (VPS[i - 1] == ')')judge++;
            else judge--;
            if (judge < 0) {
                break;
            }
        }
        if (judge == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}