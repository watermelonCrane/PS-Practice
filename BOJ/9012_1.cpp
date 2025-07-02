//230507

#include <cstdio>
#include <vector>
#include <cstring>


int main() {
    int T;
    scanf("%d", &T);
    
    char str[51];
    std::vector<bool> VPS;      //true == '('
    for (int i = 0; i < T; i++) {
        scanf("%s", str);

        for (int i = 0; i < strlen(str) + 1; i++) {

            if (str[i] == '(') VPS.push_back(true);

            else if (str[i] == ')') {
                if (VPS.size() == 0) {
                    printf("NO\n");
                    break;
                }
                else VPS.pop_back();
            }
            else if (str[i] == '\0') {
                if (VPS.size() == 0) printf("YES\n");
                else printf("NO\n");
            }
        }

        VPS.clear();
    }


    return 0;
}