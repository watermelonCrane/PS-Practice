//너무 무식하게 풀었다..
//일단 dfs부터 공부하고 오자.
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Node{
public:
    int number;
    int level;
    int childcount = 0;
    vector<Node*> children;
    vector<int> childrenMaxLevel;
    Node* parent;

    Node(int num): number(num) {}
};

class Tree{
public:
    vector<Node*> nodeList;
    int N;

    Tree(int N): N(N) {}

    void makeTree(vector<int> nodeNum) {
        //input node
        for (int i = 0; i < N; i++) {
            Node* newNode = new Node(i);
            nodeList.push_back(newNode);

            int parent = nodeNum[i];

            if (parent == -1) {
                newNode->parent = nullptr;
                continue;                
            }
            newNode->parent = nodeList[parent];
            nodeList[parent]->children.push_back(newNode);
            nodeList[parent]->childrenMaxLevel.push_back(0);

            for (Node* ptpt = newNode->parent; ptpt; ptpt = ptpt->parent) {
                ptpt->childcount++;
            }

            //countlevel
            int countlevel = 0;
            for (Node* parentNode = newNode->parent; parentNode; parentNode = parentNode->parent) {
                countlevel++;
            }
            newNode->level = countlevel;
        }

        //init childrenMaxLevel
        for (int i = N - 1; i > 0; i--) {
            int myindex = nodeList[i]->parent->children.size() - 1;
            for (;nodeList[i]->parent->children[myindex]->number != i; myindex--);

            if (nodeList[i]->children.empty()) {
                nodeList[i]->parent->childrenMaxLevel[myindex] = nodeList[i]->level;
            }
            else {
                int maxLevel = 0;
                for (auto& x: nodeList[i]->childrenMaxLevel) {
                    if (x > maxLevel) maxLevel = x;
                }
                nodeList[i]->parent->childrenMaxLevel[myindex] = maxLevel;
            }
        }
    }

    int message_1() {
        int count = 0;
        list<Node*> messenger;
        list<Node*> futureMessenger;
        Node* nodePointer;

        messenger.push_back(nodeList[0]);

        while (!messenger.empty()) {
            bool ismessege = false;
            for (auto x = messenger.begin(); x != messenger.end();) {
                if (!(*x)->children.empty() && *max_element((*x)->childrenMaxLevel.begin(), (*x)->childrenMaxLevel.end()) != -1) {
                    int max = 0;
                    int tmp = 0;
                    for (int i = 0; i < (*x)->childrenMaxLevel.size(); i++) {       //조건을 잘못 생각했음. 깊이만 깊은게 아니라 깊이가 가장 깊으면서 자손들도 많아야 함. 이게 맞나..
                        if ((*x)->childrenMaxLevel[i] > max) {
                            tmp = i;
                            max = (*x)->childrenMaxLevel[i];                    
                        }
                        else if ((*x)->childrenMaxLevel[i] == max) {
                            if ((*x)->children[i]->childcount > (*x)->children[tmp]->childcount) {
                                tmp = i;
                                max = (*x)->childrenMaxLevel[i];   
                            }                                             
                        }
                        
                    }
                    nodePointer = (*x)->children[tmp];
                    futureMessenger.push_back(nodePointer);
                    ismessege = true;
                    (*x)->childrenMaxLevel[tmp] = -1;
                }
                if (!messenger.empty() && !(*x)->children.empty() && *max_element((*x)->childrenMaxLevel.begin(), (*x)->childrenMaxLevel.end()) == -1){
                    x = messenger.erase(x);
                }
                else if (!messenger.empty() && (*x)->children.empty()) {
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

    int message_2() {
        int count = 0;
        list<Node*> messenger;
        list<Node*> futureMessenger;
        Node* nodePointer;

        messenger.push_back(nodeList[0]);

        while(!messenger.empty()) {
            bool ismessege = false;
            for (auto x = messenger.begin(); x != messenger.end();) {
                if (!(*x)->children.empty() && *max_element((*x)->childrenMaxLevel.begin(), (*x)->childrenMaxLevel.end()) != -1) {
                    int tmp = 0;
                    for (int i = 0; i < (*x)->children.size(); i++) {
                        if ((*x)->children[i]->childcount >= (*x)->children[tmp]->childcount && (*x)->childrenMaxLevel[i] != -1) {
                            tmp = i;
                        }
                    }
                    nodePointer = (*x)->children[tmp];
                    futureMessenger.push_back(nodePointer);
                    ismessege = true;
                    (*x)->childrenMaxLevel[tmp] = -1;
                }
                if (!messenger.empty() && !(*x)->children.empty() && *max_element((*x)->childrenMaxLevel.begin(), (*x)->childrenMaxLevel.end()) == -1){
                    x = messenger.erase(x);
                }
                else if (!messenger.empty() && (*x)->children.empty()) {
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
    vector<int> nodeNum(N);
    
    for (auto& x: nodeNum) {
        cin >> x;
    }
    

    Tree employee(N);
    employee.makeTree(nodeNum);

    Tree employee2(N);
    employee2.makeTree(nodeNum);

    int a = employee.message_1();
    int b = employee2.message_2();

    cout << (a < b ? a : b);

    return 0;
}