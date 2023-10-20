//실패!
//만드는중 d == 2 부분, 자손의 수를 세야한다.... 어떻게? 정렬도 안되어있는데 말이야!! 
// 깊이의 순서대로 정렬이 필요하지 않을까? -- levelorder
// 다시 생각해보자!

/// 문제를 잘못 이해했었다. d는 계속 늘어날 수 있는 거였음. d 만큼의 밑 세대를 알아내라는 거였음.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Node {
public:
    string name;
    vector<Node*> child;
    int grandchildren = 0;
    Node* parent = nullptr;
    Node(string name): name(name) {}
};

bool compare(Node* n1, Node* n2) {
    int child1 = n1->child.size();
    int child2 = n2->child.size();
    if (child1 == child2) {
        return n1->name < n2->name;
    }
    else {
        return child1 > child2;
    }
}

bool compare2(Node* n1, Node* n2) {
    int gc1 = n1->grandchildren - n1->child.size();
    int gc2 = n2->grandchildren - n2->child.size();
    if (gc1 == gc2) {
        return n1->name < n2->name;
    }
    else {
        return gc1 > gc2;
    }
}

void makeLevelorder(Node* root, vector<Node*>& result) {
    deque<Node*> queue;
    queue.push_back(root);
    result.push_back(queue.front());
    while (!queue.empty()) {
        for (auto& x: queue.front()->child) {
            result.push_back(x);
            queue.push_back(x);
        }
        queue.pop_front();
    }
}

Node* findRoot(Node* child) {
    while (child->parent) child = child->parent;
    return child;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int cnt = 1; cnt <= T; cnt++) {
        int n, d;
        cin >> n >> d;

        vector<Node*> Tree;

        while (n--) {
            string name;
            int cnum;
            cin >> name >> cnum;
            auto it = Tree.begin();
            if (!Tree.empty()) {
                for (; it != Tree.end(); it++) {
                    if (name == (*it)->name) break;
                }
                if (it == Tree.end()) {
                    Tree.push_back(new Node(name));
                    it = Tree.end() - 1;
                }                
            }
            else {
                Tree.push_back(new Node(name));
                it = Tree.end() - 1;
            }

            Node* pt = *it;

            while (cnum--) {
                string dname;
                cin >> dname;

                auto dit = Tree.begin();
                for (; dit != Tree.end(); dit++) {
                    if (dname == (*dit)->name) break;
                }
                if (dit != Tree.end()) {
                    pt->child.push_back(*dit);
                    (*dit)->parent = pt;
                }
                else {
                    pt->child.push_back(new Node(dname));
                    pt->child.back()->parent = pt;
                    Tree.push_back(pt->child.back());
                }
            }
        }

        cout << "Tree " << cnt << ":\n";
        if (d == 1) {
            sort(Tree.begin(), Tree.end(), compare);
            int i;
            for (i = 0; i < Tree.size() && i < 3; i++) {
                if (Tree[i]->child.size() <= 0) break;
                cout << Tree[i]->name << ' ' << Tree[i]->child.size() << '\n';
            }
            for (; i < Tree.size() && Tree[i]->child.size() == Tree[i - 1]->child.size(); i++) {
                if (Tree[i]->child.size() <= 0) break;
                cout << Tree[i]->name << ' ' << Tree[i]->child.size() << '\n';
            }
        }
        else if (d == 2) {
            vector<Node*> levelorder;
            Node* root = findRoot(Tree.front());
            makeLevelorder(root, levelorder);
            reverse(levelorder.begin(), levelorder.end());
            for (auto& x: levelorder) {
                int i = 0;
                for (auto p = x; i < 2 && p->parent; p = p->parent, i++) {
                    p->parent->grandchildren += 1;
                }
            }
            sort(levelorder.begin(), levelorder.end(), compare2);
            int i;
            for (i = 0; i < levelorder.size() && i < 3; i++) {
                if (levelorder[i]->grandchildren - levelorder[i]->child.size() <= 0) break;
                cout << levelorder[i]->name << ' ' << levelorder[i]->grandchildren - levelorder[i]->child.size() << '\n';
            }
            for (; i < levelorder.size() && levelorder[i]->grandchildren - levelorder[i]->child.size() == levelorder[i - 1]->grandchildren - levelorder[i - 1]->child.size(); i++) {
                if (levelorder[i]->grandchildren - levelorder[i]->child.size() <= 0) break;
                cout << levelorder[i]->name << ' ' << levelorder[i]->grandchildren - levelorder[i]->child.size() << '\n';
            }
        }

        if (cnt != T) cout << "\n";
    }

    return 0;
}