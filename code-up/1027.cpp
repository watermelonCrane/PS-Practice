#include <stdio.h>

int main() {
    int yy, mm, dd;
    scanf("%d.%d.%d", &yy, &mm, &dd);
    printf("%02d-%02d-%04d", dd, mm, yy);

    return 0;
}