#include <cstdio>


int main() {
    char str[1000001];
    scanf("%[^\n]s", str);


    int count = 0;
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ') count++;
    }

    if (str[0] == ' ') count--;
    if (str[i - 1] == ' ') count--;

    printf("%d", count + 1);

    return 0;
}