#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    list<int> lt;
    int tmp;
    list<int>::iterator it;
    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        it = find(lt.begin(), lt.end(), tmp);
        if (it != lt.end()) {
            lt.erase(it);
        }
        else {
            lt.push_back(tmp);
        }
    }
    cout << lt.front();

    return 0;
}