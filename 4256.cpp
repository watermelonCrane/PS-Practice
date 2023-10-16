//기존에 어떻게 했더라...?
//분할정복
//성공!
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

typedef vector<int>::iterator it;

void printPostorder(it startPre, it endPre, it startIn, it endIn) {
    it Proot = startPre;
    it Iroot = startIn;
    for (; *Iroot != *Proot; Iroot++);
    it newSP;
    it newEP;
    it newSI;
    it newEI;
//left subtree
    newSI = startIn;
    newEI = Iroot;
    newSP = startPre + 1;
    newEP = newSP + (newEI - newSI);
    if (newEI - newSI) {
        printPostorder(newSP, newEP, newSI, newEI);
    }
//right subtree
    newSI = Iroot + 1;
    newEI = endIn;
    if (newEI - newSI) {
        newSP = newEP;
        newEP = newSP + (newEI - newSI);
        printPostorder(newSP, newEP, newSI, newEI);
    }

//printroot
    cout << *Iroot << ' ';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> preorder(n);
        for (auto& x: preorder) cin >> x;
        vector<int> inorder(n);
        for (auto& x: inorder) cin >> x;

        printPostorder(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        cout << '\n';
    }

    return 0;
}