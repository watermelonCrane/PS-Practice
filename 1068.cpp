//dfs를 안쓰고 풀으려고...
//성공!
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Node {
public:
    int num;
    Node* p = nullptr;
    list<Node*> child;
    vector<Node*>* index;

    Node(int num, vector<Node*>* index) : num(num), index(index) {}

    ~Node() {
        (*index)[num] = nullptr;
        for (auto& x: child) {
            delete x;
        }
    }

};

class Tree {
public:
    int N;

    vector<Node*> index;

    Tree(int N) : N(N) {
        for (int i = 0; i < N; i++) {
            Node* newNode = new Node(i, &index);
            index.push_back(newNode);
        }
    }

    void makeBranch(int parent, int i) {
        index[parent]->child.push_back(index[i]);
        index[i]->p = index[parent];
    }

    int findLeaf() {
        int result = 0;
        for (auto& x: index) {
            if (x == nullptr) continue;
            if (x->child.size() == 0) result++;
        }
        return result;
    }

    void delNode(int i) {
        if (index[i]->p != nullptr) {
            list<Node*>::iterator it;
            it = find(index[i]->p->child.begin(), index[i]->p->child.end(), index[i]);

            index[i]->p->child.erase(it);
        }       

        delete index[i];
    }



};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    Tree* T = new Tree(N);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p == -1) continue;
        T->makeBranch(p, i);
    }

    cin >> N;
    T->delNode(N);

    cout << T->findLeaf();


    return 0;
}