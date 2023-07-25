//반례를 찾아서 풀었음!
//ispos에 0 이 들어가는 경우에서 생각 못한 부분이 있었음. **로 표시하였음.
//
//또한, 이전 시도에서는 이 문제를 차가 최소인 숫자를 구해서 푸는 방식으로, 
//즉 수학적인 부분을 시도해서 풀어봤었는데, 고려해야하는 부분도 많고, 생각하지 못하는 부분도 많아서
//이 방법은 적절하지 않았음.
//결국, 채택한 방법은 0부터 999999까지 모든 숫자를 입력 가능여부를 판단하고, 키 입력수가 최소인 것을 찾아서 출력하는 방법이었음.
//처음 기본채널에서 +-로만 목표채널까지 가는 키 입력수를 구해놓고, 모든 수에서 키 입력수가 최소인 것을 구해서 이 둘중 더 작은 수를 출력하게 했음.

 
#include <cstdio>
#include <cmath>


int countNum(int N);        //자리수를 세는 함수
bool ispos(int N);          //입력이 가능한 숫자들로 이루어 져 있는지 확인

bool banlist[10];   //고장난 버튼 표시. true는 고장남을 의미함.

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int udcount = abs(N - 100); //기본 채널에서 +-로만 이동할 때의 횟수.

    if (M == 0) {       //M 이 0일 때는 바로 답을 출력한다.
        int count = countNum(N);
        printf("%d", udcount < count ? udcount : count);
        return 0;
    }

    int tmp;
    for (int i = 0; i < M; i++) {       //고장난 버튼 입력
        scanf("%d", &tmp);
        banlist[tmp] = true;
    }

    int less = 9999999;     //비교를 위한 큰 숫자.
    for (int i = 0; i <= 999999; i++) {      //0부터 999999까지 모두 비교
        if (ispos(i) == true) {
            tmp = countNum(i) + abs(N - i);
            if (tmp < less) less = tmp;
        }
    }

    printf("%d", udcount < less ? udcount : less);


    return 0;
}

int countNum(int N) {
    if (N == 0) return 1;   //0 이 들어왔을 때도 한자리수로 표시한다.
    //개선 가능한 부분!!!! do while구문을 사용하면 되었다!!

    int count = 0;

    while (N) {
        N /= 10;
        count++;
    }

    return count;
}

bool ispos(int N) {
    if (N == 0 && banlist[N] != true) return true;      //**
    else if (N == 0 && banlist[N] == true) return false;        //**
    while (N) {
        if (banlist[N % 10] == true) return false;
        else {
            N /= 10;
            continue;
        }
    }
    return true;
}