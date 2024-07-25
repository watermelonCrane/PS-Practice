//최대값 구하기 참고 https://hoho325.tistory.com/321

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Node{
public:
    int number;
    int childrennumber = 0;
    list<Node*> children;
    Node* parent;
    
    Node(int num): number(num) {}

};

class customcompare {
public:
    bool operator()(Node* a, Node* b) {
        if (a->childrennumber < b->childrennumber) {
            return true;
        }
        return false;
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> nodeList;
    int N;

    Tree(int N): N(N) {}

    void makeTree() {
        int boss;
        for (int i = 0; i < N; i++) {
            Node* newNode = new Node(i);
            nodeList.push_back(newNode);
            cin >> boss;
            if (boss == -1) {
                root = newNode;
                newNode->parent = nullptr;
                continue;
            }
            newNode->parent = nodeList[boss];
            nodeList[boss]->children.push_back(newNode);

            for (Node* ptpt = newNode->parent; ptpt; ptpt = ptpt->parent) {
                ptpt->childrennumber++;
            }
        }
    }

    int message() {
        int count = 0;
        customcompare cmp;
        list<Node*> messenger;
        list<Node*> futureMessenger;
        list<Node*>::iterator nodePointer;
        
        messenger.push_back(root);

        while (!messenger.empty()) {
            bool ismessege = false;
            for (auto x = messenger.begin(); x != messenger.end(); ) {
                if (!(*x)->children.empty()) {
                    nodePointer = max_element((*x)->children.begin(), (*x)->children.end(), cmp);
                    futureMessenger.push_back(*nodePointer);
                    ismessege = true;
                    (*x)->children.erase(nodePointer);                    
                }
                if (!messenger.empty() && (*x)->children.size() == 0) {
                    x = messenger.erase(x);
                }
                else x++;
            }
            if (ismessege) count++;
            for (auto& x: futureMessenger) {
                messenger.push_back(x);
            }
            futureMessenger.clear();
        }

        return count;
    }


};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    
    Tree employee(N);
    employee.makeTree();

    cout << employee.message();


    return 0;
}