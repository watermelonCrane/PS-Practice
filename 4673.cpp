#include <cstdio>



int main() {

    bool isnSelf[10001] = {0, };
    
    for (int i = 1; i < 10000; i++) {
        int d = i;  //maked self num
        int tmp = i;    // 나누고 쪼게고 할 변수
        for (;tmp != 0;) {
            if (d > 10000) break;   // isnSelf 배열 범위 넘어가지 않게 보호
            d += tmp % 10;
            tmp /= 10;
        }
        if (d > 10000) continue;    // isnSelf 배열 범위 넘어가지 않게 보호
        isnSelf[d] = true;
    }

    for (int i = 1; i < 10001; i++) {
        if (!isnSelf[i]) printf("%d\n", i);
    }

    return 0;
}