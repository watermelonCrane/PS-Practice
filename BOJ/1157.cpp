#include <cstdio>
#include <cstring>

int main() {
    int alpha[26] = {0, };
    char S[1000001];
    scanf("%s", S);

    int count = strlen(S);
    for (int i = 0; i <= count; i++) {
        if (S[i] >= 97 && S[i] <=122) {
            alpha[S[i] - 97]++;
        }
        else if (S[i] >= 65 && S[i] <= 90) {
            alpha[S[i] - 65]++;
        }
    }

    int max = 0;
    int wmax = 0;
    for (int i = 0; i < 26; i++) {
        if (max < alpha[i]) {
            max = alpha[i];
            wmax = i + 65;
        }
        else if (max == alpha[i]) {
            wmax = 0;
        }
    }
    
    if (wmax == 0) printf("?");
    else printf("%c", wmax);



    return 0;
}