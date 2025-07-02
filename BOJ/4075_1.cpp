//성공!
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
    int gc1 = n1->grandchildren;
    int gc2 = n2->grandchildren;
    if (gc1 == gc2) return n1->name < n2->name;
    else return gc1 > gc2;
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

        vector<Node*> levelorder;
        Node* root = findRoot(Tree.front());
        makeLevelorder(root, levelorder);
        reverse(levelorder.begin(), levelorder.end());

        for (auto& x: levelorder) {
            auto p = x;
            for (int i = 0; p && i < d; i++) {
                p = p->parent;
            }
            if (p) p->grandchildren++;
        }

        sort(levelorder.begin(), levelorder.end(), compare);
        
        cout << "Tree " << cnt << ":\n";
        int i;
        for (i = 0; i < levelorder.size() && i < 3; i++) {
            if (levelorder[i]->grandchildren <= 0) break;
            cout << levelorder[i]->name << ' ' << levelorder[i]->grandchildren << '\n';
        }
        for (; i != 0 && i < levelorder.size() && levelorder[i]->grandchildren == levelorder[i - 1]->grandchildren; i++) {
            if (levelorder[i]->grandchildren <= 0) break;
            cout << levelorder[i]->name << ' ' << levelorder[i]->grandchildren << '\n';
        }

        if (cnt != T) cout << '\n';
    }

    return 0;
}