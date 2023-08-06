//런타임 에러
#include <iostream>
#include <vector>
#include <string>


bool find(std::vector<std::string> log, std::string tmp);


int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, QM;
    std::vector<std::string> log;
    std::string tmp;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        if (tmp == "?") QM = i;
        log.push_back(tmp);
    }

    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> tmp;
        if (QM == 0) {
            if (tmp.back() == log[QM + 1].front()) {
                if (find(log, tmp) == false) {
                    std::cout << tmp;
                }
            }
        }
        else if (QM == log.size() - 1) {
            if (tmp.front() == log[QM - 1].back()) {
                if (find(log, tmp) == false) {
                    std::cout << tmp;
                }
            }
        }
        else {
            if (tmp.back() == log[QM + 1].front() && tmp.front() == log[QM - 1].back()) {
                if (find(log, tmp) == false) {
                    std::cout << tmp;
                }
            }
        }
    }

    return 0;
}

bool find(std::vector<std::string> log, std::string tmp) {
    for (auto iter = log.begin(); iter != log.end(); iter++) {
        if (*iter == tmp) return true;
    }
    return false;
}