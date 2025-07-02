//참고 https://stackoverflow.com/questions/56637297/vector-of-pointer-points-to-null-when-using-push-back
//일단 성공
//recursive하게 구현하였음.
//다시 다른 구현 방법을 이용해보자. 스택을 사용하지 않는 방법으로!

#include <iostream>
#include <vector>
using namespace std;

class Tree {
private:
    class Node {
    public:
        char name;
        Node* Lchild = nullptr;
        Node* Rchild = nullptr;
        Node(char name): name(name) {}
    };
public:
    Node* root = nullptr;
    vector<Node*> index;
    int NumberofTree;

    Tree(int num): NumberofTree(num) {}

    void makeTree() {
        int N = NumberofTree;
        while(N--) {
            vector<char> inputNode(3);
            for (auto& x: inputNode) {
                cin >> x;
            }

            vector<Node*>::iterator it;

            if (inputNode[0] == 'A') {
                index.push_back(new Node('A'));
                root = index.front();
                it = index.end() - 1;
            }
            else {
                for (it = index.begin(); it != index.end(); it++) {
                    if ((*it)->name == inputNode[0]) break;
                }
            }
            
            
            Node* Lchild = nullptr;
            Node* Rchild = nullptr;

            if (inputNode[1] != '.') {
                Lchild = new Node(inputNode[1]);
                (*it)->Lchild = Lchild;
            }
            if (inputNode[2] != '.') {
                Rchild = new Node(inputNode[2]);
                (*it)->Rchild = Rchild;
            }
            if (Lchild) index.push_back(Lchild);
            if (Rchild) index.push_back(Rchild);
        }
    }

    void Preorder(Node* root) {
        if (root) {
            cout << root->name;
            Preorder(root->Lchild);
            Preorder(root->Rchild);
        }
    }
    void Inorder(Node* root) {
        if (root) {
            Inorder(root->Lchild);
            cout << root->name;
            Inorder(root->Rchild);
        }
    }
    void Postorder(Node* root) {
        if (root) {
            Postorder(root->Lchild);
            Postorder(root->Rchild);
            cout << root->name;
        }
    }

};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    Tree t(N);
    t.makeTree();

    t.Preorder(t.root);
    cout << '\n';
    t.Inorder(t.root);
    cout << '\n';
    t.Postorder(t.root);
    
    return 0;
}