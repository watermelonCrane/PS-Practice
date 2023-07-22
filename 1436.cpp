#include <cstdio>

//666이 들어가는 수를 종말의 수라고 가정

bool judgeEnd(int num) {    //종말의 수인지 판단.
    for(;num >= 666;) {
        if (num % 1000 == 666) return true;
        else {
            num /= 10;
        }
    }
    return false;
}


int main() {

    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i = 1; ; i++) {
        if (judgeEnd(i)) count++;
        if (count == N) {
            printf("%d", i);
            break;
        }
    }


    return 0;
}