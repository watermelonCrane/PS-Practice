#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

std::string makeHead(std::string ice);
std::string makeReverse(std::string ice);
std::string makeTail(std::string ice);
int judge3Combo(std::string ice);

int main() {
    int T;
    scanf("%d", &T);

    std::string ice;
    int judge;
    for (int i = 0; i < T; i++) {
        std::cin >> ice;
        std::cout << judge3Combo(ice) << '\n';
    }


    return 0;
}

std::string makeHead(std::string ice) {
    double length = ice.length();
    int ceilLength = ceil(length/3);
    ice.resize(ceilLength);
    return ice;
}

std::string makeReverse(std::string ice) {
    std::reverse(ice.begin(), ice.end());
    return ice;
}
std::string makeTail(std::string ice) {
    int length = ice.length();
    std::reverse(ice.begin(), ice.end());
    ice.resize(length - 1);
    std::reverse(ice.begin(), ice.end());
    return ice;
}

int judge3Combo(std::string ice) {
    std::string revhead, revtail, head;

    head = makeHead(ice);
    revhead = makeReverse(head);
    revtail = makeTail(head);
    
    if (ice == head + revhead + head) return 1;
    if (ice == head + makeTail(revhead) + head) return 1;
    if (ice == head + revhead + revtail) return 1;
    if (ice == head + makeTail(revhead) + revtail) return 1;

    return 0;
}