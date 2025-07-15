// 시간초과
// 예상 이유: head를 계속 유지하였기 때문에 tree가 unbalanced 하게 형성되었을 것이다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tree {
private:
    class Node {
    private:
        int data;
        Node* right;
        Node* left;
    public:
        Node(int data): data(data), right(nullptr), left(nullptr) {}


        int getData() {
            return data;
        }

        Node* getRight() {
            return right;
        }

        Node* getLeft() {
            return left;
        }

        void setLeft(Node* child) {
            left = child;
        }

        void setRight(Node* child) {
            right = child;
        }

        bool operator<(const Node& second) const {
            return this->data < second.data;
        }

        bool operator==(const Node& second) const {
            return this->data == second.data;
        }

        bool operator<(int second) const {
            return this->data < second;
        }

        bool operator==(int second) const {
            return this->data == second;
        }
    };

    Node* head;

public:

    Tree() {
        head = nullptr;
    }

    void push(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {head = node; return;}

        Node* pointer = head;

        for (; ;) {
            if (*pointer == *node) return;
            else if (*node < *pointer) {
                if (pointer->getLeft() == nullptr) {
                    pointer->setLeft(node);
                    return;
                }
                else {
                    pointer = pointer->getLeft();
                    continue;
                }
            }
            else {
                if (pointer->getRight() == nullptr) {
                    pointer->setRight(node);
                    return;
                }
                else {
                    pointer = pointer->getRight();
                    continue;
                }
            }
        }
        
    }


    Node* search(int data) {

        Node* pointer = head;

        for (; pointer != nullptr;) {
            if (*pointer == data) {
                break;
            }
            else if (*pointer < data) {
                pointer = pointer->getRight();
            }
            else {
                pointer = pointer->getLeft();
            }
        }
        
        return pointer;
    }

    

};


int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int N;
    cin >> N;

    Tree* Ns = new Tree();
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        Ns->push(data);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int data;
        cin >> data;
        if (Ns->search(data) != nullptr) cout << '1';
        else cout << '0';
        cout << '\n';
    }


}