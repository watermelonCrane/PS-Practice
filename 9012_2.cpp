//230507

//객체지향적으로 생각할 수 있을까?
#include <cstdio>
#include <vector>
#include <cstring>

int judgeChar(char tmp);
void inputStr(char* str);
void judgeVPS(char* str, std::vector<bool>& VPS);

int main() {
    int T;
    scanf("%d", &T);

    char str[51];
    std::vector<bool> VPS; //ture == '('

    for (int i = 0; i < T; i++) {
        inputStr(str);
        judgeVPS(str, VPS);
    }

    return 0;
}

int judgeChar(char tmp) {
    if (tmp == '(') return 0;
    else if (tmp == ')') return 1;
    else if (tmp == '\0') return 2;
}

void inputStr(char* str) {
    scanf("%s", str);
}

void judgeVPS(char* str, std::vector<bool>& VPS) {
    for (int i = 0; i < strlen(str) + 1; i++) {
        if (judgeChar(str[i]) == 0) VPS.push_back(true);
        else if (judgeChar(str[i]) == 1) {
            if (VPS.size() == 0) {
                printf("NO\n");
                return;
            }
            else VPS.pop_back();
        }
        else if (judgeChar(str[i]) == 2) {
            if (VPS.size() == 0) printf("YES\n");
            else printf("NO\n");
            VPS.clear();
        }
    }
}