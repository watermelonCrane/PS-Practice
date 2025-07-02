#include <cstdio>

int main() {
    bool student[31] = {0, };
    student[0] = true;
    for (int i = 0; i < 28; i++) {
        int tmp;
        scanf("%d", &tmp);
        student[tmp] = true;
    }
    for (int i = 0; i < 31; i++) {
        if(student[i] == false) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}