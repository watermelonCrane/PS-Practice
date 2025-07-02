#include <cstdio>
#include <cstring>

int main() {

    char S[101];
    scanf("%s", S); 

    for (int i = 97; i < 123; i++) {
        for (int k = 0; k < strlen(S) + 1; k++) {
            if (k == strlen(S)) {
                printf("-1 ");
                break;
            }
            if (S[k] == i) {
                printf("%d ", k);
                break;
            }
            
        }
    }

    return 0;
}