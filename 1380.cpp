//틀렸습니다.
//왜 틀렸을까요? 수정사항의 주석을 잘 읽어보세용

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Girl {
public:
    string name;
    int num;
    int AB;    //0 == A, 1 == B, 2 == return to her her necklace;

    Girl(string name, int num) {
        this->name = name;
        this->num = num;
    }

};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int sinario = 1;
    while (1) {
        cin >> n;
        cin.ignore();
        if (n == 0) break;

        vector<Girl> girlList;

        string name;
        for (int i = 1; i <= n; i++) {
            getline(cin, name);
            girlList.push_back(Girl(name, i));
        }

        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            cin >> name;
        }
        
        vector<int> isreturn(n + 1, 0);
        for (int i = 1; i <= n - 1; i++) {
            cin >> tmp;
            cin >> name;
            isreturn[tmp] = 1;
        }
        int i;
        for (i = 1; i <= n; i++) {
            if (isreturn[i] == 0) break;
        }

        cout << sinario << " " << girlList[i-1].name << "\n";

        sinario++;
    }


    return 0;
}