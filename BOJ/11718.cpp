#include <cstdio>

int main() {
    char line[101];

    while (scanf("%[^\n]s", line) != EOF) {
        printf("%s\n", line);
        getchar();
    }


}