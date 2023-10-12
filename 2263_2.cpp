//야호!!!!! 성공!!!!!!!
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int>::iterator it;

void printPreorder(it root, it startI, it endI, it startP, it endP) {
    cout << *root << ' ';

    it newSI = startI;
    it newEI = startI;
    for (; *newEI != *root; newEI++);

    it newSP = startP;
    it newEP = startP;
    for (; newEP - newSP != newEI - newSI; newEP++);

    if (newEI - newSI != 0) {
        printPreorder(newEP - 1, newSI, newEI, newSP, newEP);
    }

    newSI = newEI + 1;
    newEI = endI;

    newSP = newEP;
    newEP = endP - 1;

    if (newEI - newSI != 0) {
        printPreorder(newEP - 1, newSI, newEI, newSP, newEP);
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> inorder(n);
    for (auto& x: inorder) {
        cin >> x;
    }
    vector<int> postorder(n);
    for (auto& x: postorder) {
        cin >> x;
    }

    it root = postorder.end();
    root--;
    printPreorder(root, inorder.begin(), inorder.end(), postorder.begin(), postorder.end());

    return 0;
}