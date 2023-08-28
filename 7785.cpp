//시간초과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Employee {
public:
    string name;
    bool isenter;

    Employee(string name) : name(name) {}

    bool operator==(const Employee& a) {
        return name == a.name;
    }

    bool operator>(const Employee& a) {
        return name > a.name;
    }
    
};

bool compare(Employee& a, Employee& b) {
    return a > b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<Employee> log;
    for (int i = 0; i < n; i++) {
        string name;
        string enter;
        cin >> name >> enter;
        Employee emp(name);

        vector<Employee>::iterator it;
        it = find(log.begin(), log.end(), emp);
        if (it == log.end()) {
            log.push_back(emp);
            log.back().isenter = true;
        }
        else {
            it->isenter = false;
        }
    }

    sort(log.begin(), log.end(), compare);

    for (auto& x : log) {
        if (x.isenter) {
            cout << x.name << "\n";
        }
    }

    return 0;
}