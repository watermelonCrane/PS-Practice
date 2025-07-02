/*
만점
수행시간 : 0.04139 초
점수 : 100 점
*/

#include <iostream>
#include <string>

using namespace std;

int Answer;

string::iterator nextIter(string::iterator it, string& str) {
    string::iterator newIt = it;
    
    do {
        newIt++;
    } while (*newIt != 'A' && newIt  != str.end());

    if (newIt != str.end()) return newIt;
    else return it;
}

int insert_B(string& str) {

    int numB = 0;
    string::iterator it_front, it_back;
    

    it_front = it_back = str.begin();
    if (*it_front != 'A') {
        it_front = nextIter(it_front, str);
        it_back = nextIter(it_back, str);
    }
    it_back = nextIter(it_back, str);

    while (it_front != it_back) {
        string::iterator ff = it_front - 1;
        string::iterator fb = it_front + 1;
        string::iterator bf = it_back - 1;
        string::iterator bb = it_back + 1;

        int B = 0;
        for (;it_front != it_back; it_front++) {
            B++;
        }
        it_back = nextIter(it_back, str);
        if (B >= 3) continue;
        numB += 3 - B;
    }

    return numB;
}


int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T, test_case;
    int N;
    string str;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {
        cin >> N;
        cin >> str;

		Answer = insert_B(str);
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}