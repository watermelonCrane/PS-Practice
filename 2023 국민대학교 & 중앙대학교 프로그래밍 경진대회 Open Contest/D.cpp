//왜 출력초과?
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Youtuber {
public:
    string name;
    vector<int> day;
    vector<int>::iterator it;

    pair<int, int> sumoftime;

    Youtuber(string name, pair<int, int> sumoftime): name(name), sumoftime(sumoftime) {}

    bool verifyHonmono(int M) {
        int count = 0;
        for (int i = 7; i <= M; i += 7) {
            for (it = day.begin(); it < day.end() && *it <= i; it++) {
                count++;
            }
            if (count >= 5) count = 0;
            else {
                return false;
            }
        }
        return true;
    }

    bool operator==(const string& name) {
        return this->name == name;
    }
    bool operator<(const Youtuber& A) {
        return this->name < A.name;
    }

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<Youtuber> Ylist;
    vector<Youtuber>::iterator it;
    for (int i = 0; i < N; i++) {
        string name;
        int day;
        pair<int, int> start, end, time;
        string tmp1, tmp2;
        int tmp;

        cin >> name >> day >> tmp1 >> tmp2;

        tmp = stoi(tmp1);
        start.first = tmp;
        tmp1.erase(0, 3);
        tmp = stoi(tmp1);
        start.second = tmp;

        tmp = stoi(tmp2);
        end.first = tmp;
        tmp2.erase(0, 3);
        tmp = stoi(tmp2);
        end.second = tmp;

        if (end.second >= start.second) {
            time.second = end.second - start.second;
            time.first = end.first - start.first;
        }
        else {
            time.second = 60 + end.second - start.second;
            time.first = end.first - 1 - start.first;
        }
    

        if (day == 1) {
            Youtuber A(name, time);
            A.day.push_back(day);
            Ylist.push_back(A);
        }
        else {
            it = find(Ylist.begin(), Ylist.end(), name);
            (*it).sumoftime.first += time.first;
            (*it).sumoftime.second += time.second;
            (*it).day.push_back(day);
        }
    }

    sort(Ylist.begin(), Ylist.end());

    bool isprint = false;
    for (auto& x: Ylist) {
        if (x.sumoftime.first >= 60 && x.verifyHonmono(M)) {
            cout << x.name << '\n';
            isprint = true;
        }
    }
    if (isprint == false) cout << -1;

    return 0;
}