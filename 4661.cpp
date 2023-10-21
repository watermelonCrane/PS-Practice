//걍 BST 구현하면 되는거 아님?
//ㅋㅋ 걍 Bst구현해서 정답 나옴 ㅋㅋ
// 성공!
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BST {
private:
    class Node {
    public:
        char name;
        Node* Lchild = nullptr;
        Node* Rchild = nullptr;
        Node* parent = nullptr;
        Node(char name): name(name) {}
    };
public:
    Node* root;

    BST(char rootname) {
        root = new Node(rootname);
    }

    bool isBigger(Node* node, char data) {
        return node->name < data;
    }

    void inputData(char data) {
        Node* newNode = new Node(data);
        Node* pt = root;
        bool right = true;
        while (1) {
            if (isBigger(pt, data)) {
                right = true;
                if (pt->Rchild) {
                    pt = pt->Rchild;
                }
                else {
                    break;
                }
            }
            else {
                right = false;
                if (pt->Lchild) {
                    pt = pt->Lchild;
                }
                else {
                    break;
                }
            }
        }

        if (right) {
            pt->Rchild = newNode;
        }
        else {
            pt->Lchild = newNode;
        }
        newNode->parent = pt;
    }

private:
    void preorder(Node* r) {
        if (r) {
            cout << r->name;
            preorder(r->Lchild);
            preorder(r->Rchild);
        }
    }

public:
    void printPreorder() {
        preorder(root);
    }
    

};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (1) {
        bool isend = false;
        vector<string> data;
        string str;
        do {
            cin >> str;
            data.push_back(str);
            if (str == "$") isend = true;
        } while (str != "*" && str != "$");
        data.pop_back();        //delete '*'

        BST T(data.back()[0]);
        data.pop_back();

        while(!data.empty()) {
            for (auto it = data.back().begin(); it != data.back().end(); it++) {
                T.inputData(*it);
            }
            data.pop_back();
        }

        T.printPreorder();
        cout << '\n';
        if (isend) break;
    }

    return 0;
}