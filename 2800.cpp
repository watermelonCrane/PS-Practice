//옛날에 고민하던거..이땐 실패함

//코드 짜는 것에 질려서 다른사람들의 풀이를 대강 살펴보았다. 일단 나의 접근은 올바르다.
//대응되는 괄호를 스택에서 푸시 팝 하며 괄호의 인덱스를 따로 저장하고, 이것들의 조합을 구하여서 괄호를 제외하고 문자열을 출력시키는 것이다.
//하지만 사전순 출력은 모르겠다. 다른 풀이에선 map의 기능을 사용하던데, 일단 이 부분은 제외하고 구현하는 것 까지를 목표로 하자ㅏ.
//순열과 조합 공부부터 시작이다.
//그래프를 공부한 후에, dfs를 이용해서 조합을 구하는 방법이 있다고 한다. 그걸 해보자.

//2023-09-13
//어지저찌 성공은 함, 단순 재귀를 이용해(나름 dfs? 백트래킹?)조합을 구하였다. (백준 N과 M 문제를 참고함.)
//그런데 여기서 더 깔끔하게 코드를 짤 수는 없을 까 궁금해졌음
//단순히 괄호 위치의 조합만 구해가지고는 걸러내지 못하는 중복이 있음. 아래와 같은 예시
//   (((1)))(2)
//괄호가 없어지는게 다른 위치의 괄호가 없어지더라도 같은 형태가 될 수 있음 <-뭔말인지 모르겠으면 이 말은 무시하자
// 현재 코드에서는 82번째 줄에서 프린트를 할 때 중복을 확인하고 프린트 하도록 코드를 구성했음

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void NM(int N, int M, vector<int>& tmp, vector<vector<int>>& Com, int i) {
    if (tmp.size() == M) {
        Com.push_back(vector<int>());
        for (auto& x: tmp) {
            Com.back().push_back(x);
        }
    }
    else {
        for (; i < N; i++) {
            tmp.push_back(i);
            NM(N, M, tmp, Com, i + 1);
        }
    }
    if (tmp.size() != 0) tmp.pop_back();
}

int main() {
    string susik;
    cin >> susik;

    vector<int> bra;
    vector<pair<int, int>> braPair;
    for (int i = 0; i < susik.size(); i++) {
        if (susik[i] == '(') {
            bra.push_back(i);
        }
        else if (susik[i] == ')') {
            braPair.push_back({bra.back(), i});
            bra.pop_back();
        }
    }

    vector<int> tmp;
    vector<vector<int>> Com;

    for (int i = 1; i <= braPair.size(); i++) {     //조합구하기
        NM(braPair.size(), i, tmp, Com, 0);
    }

    //NM(braPair.size(), 1, tmp, Com, 0);
    

    vector<string> result(Com.size(), susik);
    for (int i = 0; i < Com.size(); i++) {
        for (int k = 0; k < Com[i].size(); k++) {
            result[i][braPair[Com[i][k]].first] = 'x';
            result[i][braPair[Com[i][k]].second] = 'x';
        }
    }

    for (auto& x: result) {
        while (1) {
            size_t t = x.find('x');
            if (t == string::npos) break;
            x.erase(t, 1);
        }
    }
    sort(result.begin(), result.end());

    //중복을 걸러내면서 프린트
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == result[i - 1]) continue;
        cout << result[i] << '\n';
    }


    return 0;
}