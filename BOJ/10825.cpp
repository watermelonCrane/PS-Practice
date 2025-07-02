#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int Ko;
    int En;
    int Math;
    string name;
    Student(int Ko, int En, int Math, string name) : Ko(Ko), En(En), Math(Math), name(name) {}

    
    bool operator>(Student& student) {
        if (student.Ko != Ko) {
            return student.Ko > Ko;
        }
        else if (student.En != En) {
            return student.En < En;
        }
        else if (student.Math != Math) {
            return student.Math > Math;
        }
        else {
            return student.name < name;
        }
    }
};

bool compare(Student i, Student j) {
        return j > i;
    }


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Student> list;
    int Ko;
    int En;
    int Math;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name >> Ko >> En >> Math;
        Student student(Ko, En, Math, name);
        list.push_back(student);
    }

    sort(list.begin(), list.end(), compare);

    for (auto& x : list) {
        cout << x.name << "\n";
    }


    return 0;
}