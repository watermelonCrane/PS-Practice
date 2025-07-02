//어디가 잘못 됬나...
//이제 코드에서 잘못된 부분은 없다ㅏ. 단! 수많은 함수가 콜 되면서 컴퓨터가 죽어버릴 뿐.
//DP를 사용하여야 한다.
//DP를 공부하고 다시 풀어보도록 하자.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int>* sum(vector<int>* a, vector<int>* b) {
    vector<int>* newvector = new vector<int>();
    int up = 0;

    vector<int>* smallV = a->size() < b->size() ? a : b;
    vector<int>* bigV = a == smallV ? b : a;

    int i, tmp;
    for (i = 0; i < smallV->size(); i++) {
        tmp = (*a)[i] + (*b)[i] + up;
        up = tmp / 10;
        tmp %= 10;
        newvector->push_back(tmp);
    }
    for (; i < bigV->size(); i++) {
        tmp = up + (*bigV)[i];
        up = tmp / 10;
        tmp %= 10;
        newvector->push_back(tmp);
    }
    newvector->push_back(up);

    delete a;
    delete b;

    while (newvector->back() == 0 && newvector->size() != 1) {
        newvector->pop_back();
    }

    return newvector;
}

void minus1(vector<int>* a, int i) {
    if ((*a)[i] > 0) {
        (*a)[i]--;
    }
    else {
        (*a)[i] = 9;
        minus1(a, i + 1);
    }
    while (a->back() == 0 && a->size() != 1) {
        a->pop_back();
    }
}

vector<int>* clone(vector<int>* a) {
    vector<int>* newV = new vector<int>();
    for (auto& x: *a) {
        newV->push_back(x);
    }
    return newV;
}

vector<int>* pibo(vector<int>* n) {
    if (n->size() == 1) {
        if (n->back() == 0) {
            vector<int>* newV = new vector<int>();
            newV->push_back(0);
            delete n;
            return newV;
        }
        if (n->back() == 1) {
            vector<int>* newV = new vector<int>();
            newV->push_back(1);
            delete n;
            return newV;
        }
    }

    vector<int>* a = clone(n);
    vector<int>* b = clone(n);
    delete n;

    minus1(a, 0);

    minus1(b, 0);
    minus1(b, 0);

    a = pibo(a);
    b = pibo(b);

    return sum(a, b);
}



int main() {
    string str;
    cin >> str;

    vector<int>* n = new vector<int>();
    for (int i = str.size() - 1; i >= 0; i--) {
        n->push_back(str[i] - 48);
    }

    n = pibo(n);

    while (n->size() != 0) {
        cout << n->back();
        n->pop_back();
    }

    return 0;
}