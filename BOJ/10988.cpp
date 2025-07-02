#include <cstdio>
#include <cstring>

int main() {
    char word[105];
    scanf("%s", word);
    int len = strlen(word);

    int fpt = 0;
    int lpt = len - 1;

    for (; word[fpt] == word[lpt] && fpt <= lpt; fpt++, lpt--);
    if (fpt - lpt == 2 || fpt - lpt == 1) printf("1");
    else printf("0");
    
    return 0;
}

/* #include <cstdio>
#include <cstring>

int main() {
    char str[101];
    scanf("%s", str);
    int strlpt = strlen(str) - 1;

    char clone[101];
    for (int i = 0; strlpt - i != -1; i++) {
        clone[i] = str[strlpt - i];
    }
    for (int i = 0; i <= strlpt; i++) {
        if (clone[i] != str[i]) {
            printf("0");
            return 0;
        }
    }
    printf("1");
    

    return 0;
} */