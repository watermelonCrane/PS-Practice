//지금까지 생각을 잘못한 것은 압수가 먼저 나오고 돌려받는게 나중에 나오는 것만 생각을 했다.
//하지만 문제에는 그런 조건이 없고, 번호가 두번 나오면 그냥 돌려받은 것이다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Girl {
public:
    int earring = 0;    // 0 == 안뺐김 , 1 == 뺐김, 2 == 돌려받음.
    string name;
    Girl(string name) {
        this->name = name;
    }

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    int sinario = 1;
    while(1) {
        cin >> n;
        cin.ignore();
        if (n == 0) break;

        string tmp;
        vector<Girl> girlList(n + 1, Girl(" "));
        
        for (int i = 1; i <= n; i++) {
            getline(cin, tmp);
            girlList[i].name = tmp;
        }
        int foo;
        char boo;
        
        for (int i = 1; i <= 2 * n - 1; i++) {
            cin >> foo >> boo;
            girlList[foo].earring++;
        }
        for (int i = 1; i <= n; i++) {
            if (girlList[i].earring == 1) {
                cout << sinario << " " << girlList[i].name << "\n";
                break;
            }
        }

        sinario++;
    }


    return 0;
}