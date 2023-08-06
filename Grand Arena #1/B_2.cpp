#include <cstdio>
#include <cstring>

int find(int N, char** list, char* tmp);

int main() {
    int N;
    scanf("%d", &N);

    char list[100][11];
    int QM;
    for (int i = 0; i < N; i++) {
        scanf(" %s", list[i]);
        if (*list[i] = '?') QM = i; 
    }

    int M;
    scanf("%d", &M);
    char tmp[11];
    for (int i = 0; i < M; i++) {
        if (QM == 0) {
            char first = list[QM + 1][0];
            scanf(" %s", tmp);
            char tmplast;
            for (int i = 0; tmp[i] != '\0'; i++) {
                tmplast = tmp[i];
            }
            if (tmplast == first && find(N, list, tmp) == 0) printf("%s", tmp);
            break;
        }
        else if (QM == N - 1) {
            char last;
            for (int i = 0; list[QM - 1][i] != '\0'; i++) {
                last = list[QM - 1][i];
            }
            scanf(" %s", tmp);
            if (tmp[0] == last) printf("%s", tmp);
            break;
        }
        else {
            char first = list[QM + 1][0];
            char last;
            for (int i = 0; list[QM - 1][i] != '\0'; i++) {
                last = list[QM - 1][i];
            }
            scanf(" %s", tmp);
            char tmplast;
            for (int i = 0; tmp[i] != '\0'; i++) {
                tmplast = tmp[i];
            }
            if (tmp[0] == last && tmplast == first) printf("%s", tmp);
            break;
        }
    }


    return 0;
}

int find(int N, char** list, char* tmp) {
    for (int i = 0; i < N; i++) {
        if (strcmp(list[i], tmp) == 0) return 1;
    }

    return 0;
}