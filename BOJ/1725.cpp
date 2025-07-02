//왜 시간초과가 안뜨지????
//성공
//왜 성공인가..
// 기존 코드의 반례(기존코드는 아래에..)
// 10 6 5 2 3 7 4 0 3 3 3 이라는 입력이 있다고 하자.
// 기존 코드에서는 커지는 상황에 작아진 값이 나올때 stack에 올라간 인덱스를 i - 1까지 끌어다가 계산하는 식으로 구성되었었다.
// 여기서 stack의 top부터 i - 1까지를 너비로, histo[top]을 높이로 쫙 끌어다가 쓰는 원리인데, 이게 왜 가능한가?
// 계속 커지는 상황을 가정했기 때문에, i - 1까지 histo[top]보다 큼을 즉, histo[top]이 높이가 될 수 있음을 보장하는 상황이었기 때문이다. 
// 하지만 이 코드에서 작아지는 상황을 생각하면, stack에 저장하지 못하는 상황이 생긴다.
// 그래서 바뀐 코드는 stack에 작아진 값만큼은 그 전 index에서 보장한다는 정보를 추가해 준 것이다.
//  *1* 주석이 달린 코드를 참고하자.

// 시간 복잡도를 계산해보자.
// 최악의 경우를 생각해보면, N만큼의 히스토그램 정보가 입력될 때, 계속해서 작아지는 값으로 입력되는 경우가 이중반복문이 계속 실행되는 경우가 될 것이다.
// 바깥 반복문의 복잡도는 O(N + 1), 내부 반복문의 복잡도는 O(1)-- 최악이어봤자 한번만 반복하게 된다?
// 따라서 O(N)이 최악의 경우이다.

// 계속 증가하는 경우도 생각해볼까?
// 바깥 반복문은 O(N + 1), 내부는 O(N)인데, 한번만 실행 될 것이다. 따라서 O(N).

// 어떤 경우를 해봤자 선형의 복잡도가 나올 것이다.
// 라고 생각하는데, 맞는지는 모르겠다.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> stack;
    vector<int> histo;

    stack.push_back(0);
    histo.push_back(0);
    int max = 0;

    for (int i = 1; i < N + 2; i++) {
        int tmp;
        if (i == N + 1) tmp = 0;
        else cin >> tmp;

        if (i == 1) {
            histo.push_back(tmp);
            stack.push_back(i);
            continue;
        }

        if (tmp < histo[stack.back()]) {
            int lastIndex;
            while (tmp < histo[stack.back()]) {
                lastIndex = stack.back();

                int m = histo[stack.back()] * (i - stack.back());
                if (m > max) {
                    max = m;
                }

                stack.pop_back();
                
            }
            
            stack.push_back(lastIndex);     //*1*
            histo[lastIndex] = tmp;
        }

        stack.push_back(i);
        histo.push_back(tmp);
    }

    cout << max;

    return 0;
}

/* 실패했던 코드
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> stack;
    vector<int> hito;
    int max = 0;

    stack.push_back(0);
    hito.push_back(0);
    for (int i = 1; i <= N + 1; i++) {
        int tmp;
        if (i == N + 1) {
            tmp = -1;
            hito[0] = hito[stack[1]];
        }
        else {
            cin >> tmp;
        }

        if (i == 1) {
            hito.push_back(tmp);
            stack.push_back(i);
            continue;
        }

        
        if (tmp < hito.back()) {
            while (!stack.empty() && hito[stack.back()] > tmp) {
                int m = hito[stack.back()] * (i - stack.back());
                if (m > max) {
                    max = m;
                }
                stack.pop_back();
            }
        }

        hito.push_back(tmp);
        stack.push_back(i);
    }

    cout << max;

    return 0;
}
 */