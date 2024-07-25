#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> count(N, 0);
    vector<int> list;
    vector<int> stack;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (i == 0 && tmp > 1) {        //올바른가 1
            cout << -1;
            return 0;
        }
        if (i == 0) {
            stack.push_back(i);
            list.push_back(tmp);
            continue;
        }

        if (tmp > list.back() + 1) {   //올바른가2
            cout << -1;
            return 0;
        }

        list.push_back(tmp);
        if (list[stack.back()] + 1 == tmp) {
            count[stack.back()]++;
            stack.push_back(i);
        }
        else if (list[stack.back()] == tmp) {
            stack.pop_back();
            count[stack.back()]++;
            stack.push_back(i);
        }
        else {              //여기부분 이상함 다시보자.
            if (tmp == 1) {
                stack.pop_back();
                stack.push_back(i);
                continue;
            }
            stack.pop_back();
            count[stack.back()]++;
            stack.push_back(i);
        }        
    }

    for (auto& x: count) {
        cout << x << '\n';
    }

    return 0;
}