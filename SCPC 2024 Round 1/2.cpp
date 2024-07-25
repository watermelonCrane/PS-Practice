//나중에 다시 풀어보자. 구현을 잘못 시작함. 조합을 구해서 각 값을 비교하는 방식으로 

/*
철수는 N개의 물건을 배달해야 한다. N은 4의 배수이다. 철수는 각 물건의 무게를 알고 있다. 한번 나갈 때마다 철수는 4개의 물건을 한꺼번에 가져간다. 4개의 물건들의 무게가 각각 a,b,c,d라고 하자. 반드시 a≤b≤c≤d
가 되도록 물건의 무게를 정렬해야 한다. 이때, 철수가 버는 금액은 |d−c|+|c−b|+|b−a|+|a−d|
이다. N/4번의 배달에서 철수가 버는 총 금액이 가장 크도록 물건들을 잘 골라서 배달할 수 있게 도와주는 프로그램을 작성하라.

물건이 4개가 있고, 무게들이 각각 1,2,3,4라고 하자. 이 경우 철수는 단 한번, 모든 물건을 들고 나가게 된다. 이 때 버는 금액은 |4-3|+|3-2|+|2-1|+|1-4|=6이다. 이번에는 물건이 8개가 있고 무게들이 각각 1,2,3,4,5,6,7,8이라고 하자. 철수는 2번 나가게 된다. 첫번째에 가져가는 물건들의 무게가 각각 1,4,5,7이라고 하면 이때 버는 금액은 |7-5|+|5-4|+|4-1|+|1-7|=12이다. 두번째에 철수가 가져가는 물건들의 무게는 각각 2,3,6,8이 되고, 버는 금액은 |8-6|+|6-3|+|3-2|+|2-8|=12이다. 총 금액은 24가 되며, 이 금액이 가능한 가장 큰 금액이다.

- 제한시간: 전체 테스트 케이스는 50개 이하이며, 전체 수행 시간은 1.5초 이내. (Java 3초 이내) 
    제한 시간을 초과하면 제출한 소스코드의 프로그램이 즉시 종료되며, 그때까지 출력한 내용이 파일에 저장되지 않아 점수가 제대로 반영되지 않을 수 있다.
    그러나, 제한 시간을 초과하더라도 어떤 부분문제에 속해있는 테스트 케이스를 모두 통과하였다면
    해당 부분점수(0< 부분점수< 만점)를 받을 수 있으며, 이를 위해서는 각 테스트 케이스를 처리한 후 출력 버퍼를 flush해줘야 한다. 즉,
    - C / C++ 에서 "scanf / printf"를 입출력에 사용할 경우,
       프로그램 시작부분에서 "setbuf(stdout, NULL);"를 한 번 사용하고,
    - C++에서 "std::cin / std::cout"을 입출력에 사용할 경우,
       프로그램 시작부분에서 "std::ios_base::sync_with_stdio(false);"와 "std::cin.tie(NULL);"을 한 번 사용한 후,
       이후 모든 줄바꿈을 "std::cout << "\n";"대신 "std::cout << endl;"으로 사용하며,
    - Java에서는 "System.out.printIn"을 사용하면
    제한 시간을 초과하더라도 해당 부분문제의 부분점수를 받을 수 있다.     ※ 언어별 기본 제공 소스코드 내용 참고
    만약, 제한 시간을 초과하지 않았는데도 '부분 점수'를 받았다면,
    모든 부분문제에서 일부 테스트 케이스를 통과하지 못한 경우이다.


- 메모리 사용 제한 : heap, global, static 총계 512MB, stack 100MB
- 제출 제한 : 최대 10회 (제출 횟수를 반영하여 순위 결정 → 동점자의 경우 제출 횟수가 적은 사람에게 높은 순위 부여)
 

메모리 사용 제한
heap, global, static (총계) : 512MB
stack : 100MB
입력
입력 파일에는 여러 테스트 케이스가 포함될 수 있다.
파일의 첫째 줄에 테스트 케이스의 개수를 나타내는 정수 T
 가 주어지고,
이후 차례로  T
 개의 테스트 케이스가 주어진다. (1≤T≤50
) 
각 테스트 케이스의 첫 줄에는 물건의 개수를 나타내는 정수 N
이 주어진다 (4≤N≤300,000
).
N
은 4의 배수임이 보장된다.
다음 줄에 물건들의 무게들이 1 이상 1,500,000 이하의 정수로 주어진다.

- 점수 : 각 제출에서 취득한 점수 중에서 최대 점수 (만점 150점)
  주어지는 테스트 케이스 데이터들의 그룹은 아래와 같으며,
 각 그룹의 테스트 케이스를 모두 맞추었을 때 해당되는 부분 점수를 받을 수 있다.


ㆍ 그룹 1 (38점) : 4≤N≤8

ㆍ 그룹 2 (31점) : 4≤N≤20

ㆍ 그룹 3 (81점) : 추가적인 제약조건이 없다. 
출력
각 테스트 케이스의 답을 순서대로 표준출력으로 출력하여야 하며,
각 테스트 케이스마다 첫 줄에는 “Case #C”를 출력하여야 한다. 이때 C는 테스트 케이스의 번호이다.
각 테스트 케이스에 대해서 철수가 모든 물건을 배달해서 벌 수 있는 최대 금액을 정수로 출력한다.
입출력예
입력
3
4
1 2 3 4
4
1 1 1 1
8
1 2 3 4 5 6 7 8
출력
Case #1
6
Case #2
0
Case #3
24

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
vector<bool> Visited;
vector<vector<int>> Comb;


void initVisit(int N) {
    Visited.resize(N, false);
}

int make_result(vector<int>& Object) {
    return abs(Object[Comb[0][0]] - Object[Comb[0][1]]) + abs(Object[Comb[0][1]] - Object[Comb[0][2]]) + abs(Object[Comb[0][2]] - Object[Comb[0][3]]) + abs(Object[Comb[0][3]] - Object[Comb[0][0]])
            + abs(Object[Comb[1][0]] - Object[Comb[1][1]]) + abs(Object[Comb[1][1]] - Object[Comb[1][2]]) + abs(Object[Comb[1][2]] - Object[Comb[1][3]]) + abs(Object[Comb[1][3]] - Object[Comb[1][0]]);
}

void NM() {

}

int sum(vector<int>& Object) {
    vector<int> result;

    for (int i = 0; i < Object.size() / 4; i++) {
        Comb.clear();
        initVisit(Object.size());

        

        result.push_back(make_result(Object));
    }
    
    
    sort(result.begin(), result.end());
    return result.back();
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int T, test_case;
    int N;
    

	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {
        cin >> N;
        vector<int> Object(N);
        for (int i = 0; i < N; i++) cin >> Object[i];
        sort(Object.begin(), Object.end(), greater<int>());
        
		Answer = sum(Object);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}