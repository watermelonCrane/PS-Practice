//실패, 시간초과

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    char str[100001];
    int cuser = 0;
    
    scanf("%s", str);
    
    cuser = strlen(str);

    int M;
    scanf("%d", &M);

    queue<char> job;

    for (int i = 0; i < M; i++) {
        char tmp;
        scanf(" %c", &tmp);
        job.push(tmp);
        if (tmp == 'P') {
            scanf(" %c", &tmp);
            job.push(tmp);
        }
    }

    while(job.size()) {
        if (job.front() == 'L') {
            if (cuser == 0) {
                job.pop();
                continue;
            }
            cuser--;
            job.pop();
        }
        else if (job.front() == 'D') {
            if (cuser == strlen(str)) {
                job.pop();
                continue;
            }
            cuser++;
            job.pop();
        }
        else if (job.front() == 'B') {
            if (cuser == 0) {
                job.pop();
                continue;
            }
            for (int i = cuser - 1; str[i] != '\0'; i++) {
                str[i] = str[i + 1];
            }
            cuser--;
            job.pop();
        }
        else if (job.front() == 'P') {
            job.pop();
            str[strlen(str) + 1] = '\0';
            for (int i = strlen(str); i > cuser; i--) {
                str[i] = str[i - 1];
            }
            str[cuser] = job.front();
            job.pop();
            cuser++;
        }
        else {
            printf("errror\n");
        }
    }

    printf("%s", str);


    return 0;
}