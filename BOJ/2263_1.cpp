//와 ㅋㅋ 메모리 초과 뜸!
#include <iostream>
#include <vector>
using namespace std;

void printPreorder(vector<int>::iterator root, vector<int>& inorder, vector<int>& postorder) {
    cout << *root << ' ';

    vector<int>::iterator newroot;

    vector<int> newinorder;
    vector<int>::iterator iti = inorder.begin();
    for (auto& x: inorder) {
        iti++;
        if (x == *root) break;
        newinorder.push_back(x);
    }
    

    vector<int> newpostorder;
    vector<int>::iterator itp = postorder.begin();
    for (auto& x: postorder) {
        if (newpostorder.size() == newinorder.size()) break;
        newpostorder.push_back(x);
        itp++;
    }

    if (!newinorder.empty()) {
        newroot = newpostorder.end();
        newroot--;
        printPreorder(newroot, newinorder, newpostorder);
    }

    newinorder.clear();
    for (; iti != inorder.end(); iti++) {
        newinorder.push_back(*iti);
    }

    newpostorder.clear();
    for (; itp != root; itp++) {
        newpostorder.push_back(*itp);
    }

    if (!newinorder.empty()) {
        newroot = newpostorder.end();
        newroot--;
        printPreorder(newroot, newinorder, newpostorder);
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

    auto root = postorder.end();
    root--;
    printPreorder(root, inorder, postorder);



    return 0;
}