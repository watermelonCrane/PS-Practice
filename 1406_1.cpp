//성공, 연결리스트로 시간 단축
//다른풀이는 스택을 이용하는 방법이 있다함.

#include <cstdio>
#include <queue>
#include <list>
using namespace std;

int main() {
    char oristr[100001];
    int M;
    scanf("%s", oristr);
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

    list<char> str;
    for (int i = 0; oristr[i] != '\0'; i++) {
        str.push_back(oristr[i]);
    }
    list<char>::iterator iter = str.end();
    
    while(job.size()) {
        if (job.front() == 'L') {
            if (iter == str.begin()) {
                job.pop();
                continue;
            }
            iter--;
            job.pop();
        }
        else if (job.front() == 'D') {
            if (iter == str.end()) {
                job.pop();
                continue;
            }
            iter++;
            job.pop();
        }
        else if (job.front() == 'B') {
            if (iter == str.begin()) {
                job.pop();
                continue;
            }
            iter = str.erase(--iter);
            job.pop();
        }
        else if (job.front() == 'P') {
            job.pop();
            str.insert(iter, job.front());
            job.pop();
        }
        else {
            printf("errror\n");
        }
    }

    for (iter = str.begin(); iter != str.end(); iter++) {
        printf("%c", *iter);
    }


    return 0;
}