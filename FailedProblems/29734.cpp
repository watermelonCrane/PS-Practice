//실패 왜?????
#include <iostream>
using namespace std;

class Student {
public:
    int zip = 0;
    int dok = 0;
    int work_time = 0;
    int N, M, T, S;
    bool isDone = false;

    Student() {
        cin >> N >> M >> T >> S;
    }

    int Dok() {
        dok += 4;
        while (1) {
            M--;
            dok++;
            if (M == 0) break;
            work_time++;
            if (work_time == 8) {
                work_time = 0;
                Rest(2);
            }
        }
        work_time = 0;
        return dok;
    }
    int Zip() {
        while (1) {
            N--;
            zip++;
            if (N == 0) break;
            work_time++;
            if (work_time == 8) {
                work_time = 0;
                Rest(1);
            }
        }
        work_time = 0;
        return zip;
    }
    void Rest(int a) {
        if (a == 1) zip += S;
        else Go();
    }
    void Go() {
        dok += T;
        dok += S;
        dok += T;
    }
};

int main() {
    Student ss;
    
    int zip = ss.Zip();
    int dok = ss.Dok();
    
    if (zip < dok) {
        cout << "Zip\n" << ss.zip;
    }
    else {
        cout << "Dok\n" << ss.dok;
    }


    return 0;
}