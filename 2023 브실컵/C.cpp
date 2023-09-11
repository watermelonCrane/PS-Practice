//실패
#include <iostream>
#include <string>
using namespace std;

class Day {
public:
    int yyyy;
    int mm;
    int dd;
    Day(int yyyy, int mm, int dd) : yyyy(yyyy), mm(mm), dd(dd) {}

    void sumDay(int dd) {
        this->dd += dd;
        if (this->dd > 30) {
            sumMonth(this->dd / 30);
            this->dd %= 30;
        }
    }
    void sumMonth(int mm) {
        this->mm += mm;
        if (this->mm > 12) {
            sumYear(this->mm / 12);
            this->mm %= 12;
        }
    }
    void sumYear(int yyyy) {
        this->yyyy += yyyy;
    }

    void printDay() {
        cout.width(4);
        cout.fill('0');
        cout << yyyy << "-";
        
        cout.width(2);
        cout << mm << "-";

        cout.width(2);
        cout << dd;
    }
};

int main() {
    int yyyy, mm, dd;
    string tmp;
    getline(cin, tmp, '-');
    yyyy = stoi(tmp);
    getline(cin, tmp, '-');
    mm = stoi(tmp);
    getline(cin, tmp);
    dd = stoi(tmp);

    int time;
    cin >> time;

    Day day(yyyy, mm, dd);

    day.sumDay(time);
    day.printDay();

    

    return 0;
}