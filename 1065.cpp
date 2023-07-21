#include <cstdio>

bool isHansu(int num){
    if (num <= 99) return true;     //99까지는 무조건 한수임.

    char buf[4];
    sprintf(buf, "%d", num);
    for (int i = 1, dif = buf[i] - buf[i - 1]; buf[i + 1] != '\0'; i++) {
        if (buf[i + 1] != buf[i] + dif) return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (isHansu(i)) count++;
    }

    printf("%d", count);

    return 0;
}