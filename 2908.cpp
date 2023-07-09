#include <cstdio>

void printFront(char* num) {
    for (int i = 2; i >= 0; i--) {
        printf("%c", num[i]);
    }
}

void printBack(char* num) {
    for (int i = 6; i >= 4; i--) {
        printf("%c", num[i]);
    }
}

void cmpNum(char* num, int ptr1, int ptr2) {
    if (num[ptr1] > num[ptr2]) printFront(num);
    else if ( num[ptr1] < num[ptr2]) printBack(num);
    else cmpNum(num, ptr1 - 1, ptr2 - 1);
}

int main() {
    char num[8];
    scanf("%[^\n]s", num);

    cmpNum(num, 2, 6);    

    return 0;
}