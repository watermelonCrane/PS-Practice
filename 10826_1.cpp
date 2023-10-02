//성공!
//이게 되네 ㅋㅋ
//이것도 DP라고 해야하나?

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<vector<int>*>* MEMO;     //계산된 값은 저장해놓자!

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
    int ni = 0;
    for (int i = 0; i < n->size(); i++) {
        ni += static_cast<int>(pow(10, i)) * (*n)[i];
    }
    if ((*MEMO)[ni] != nullptr) {
        vector<int>* newvector = clone((*MEMO)[ni]);
        return newvector;
    }
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

    vector<int>* newvector = sum(a, b);
    vector<int>* newmemo = clone(newvector);
    (*MEMO)[ni] = newmemo;

    return newvector;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int ni = stoi(str);
    MEMO = new vector<vector<int>*>(ni + 1, nullptr);

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