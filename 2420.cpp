#include <cstdio>
#include <cmath>

int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    printf("%lld", (long long)labs(N - M));

    return 0;
}