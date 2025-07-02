//시간초과
//직접 트리를 구하는 것이 아닌, 분할정복을 통해서 바로 출력하자.
//하아...
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int num;
    Node* Lchild = nullptr;
    Node* Rchild = nullptr;

    Node(int num): num(num) {}
};

Node* rebuildTree(Node* root, vector<int>& inorder, vector<int>& postorder, vector<Node*>& Tree) {
    

    vector<int> newIn;
    int rootIndex = postorder.back();
    int i;
    for (i = 0; inorder[i] != rootIndex; i++) {
        newIn.push_back(inorder[i]);
    }
    vector<int> newPost;
    int k;
    for (k = 0; newPost.size() < newIn.size(); k++) {
        if (find(newIn.begin(), newIn.end(), postorder[k]) != newIn.end()) {
            newPost.push_back(postorder[k]);
        }
    }

    if (!newIn.empty()) {
        root->Lchild = rebuildTree(Tree[newPost.back()], newIn, newPost, Tree);
    }

    

    newIn.clear();
    for (i++; i < inorder.size(); i++) {
        newIn.push_back(inorder[i]);
    }
    newPost.clear();
    for (k = 0; newPost.size() < newIn.size(); k++) {
        if (find(newIn.begin(), newIn.end(), postorder[k]) != newIn.end()) {
            newPost.push_back(postorder[k]);
        }
    }

    if (!newIn.empty()) {
        root->Rchild = rebuildTree(Tree[newPost.back()], newIn, newPost, Tree);
    }

    return root;

}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->num << ' ';
    printPreorder(root->Lchild);
    printPreorder(root->Rchild);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> inorder(n);
    vector<int> postorder(n);

    for (auto& x: inorder) {
        cin >> x;
    }
    for (auto& x: postorder) {
        cin >> x;
    }

    vector<Node*> Tree(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        Tree[i] = new Node(i);
    }

    Node* root = rebuildTree(Tree[postorder.back()], inorder, postorder, Tree);


    printPreorder(root);

    return 0;
}