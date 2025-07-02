//dfs 안쓰고 풀기는 실패고, 이게 dfs는 맞겠지? 일단 생각나는대로 풀어봤음
//오 메모리 초과가 나는데
// 나중에 dfs 공부하고 다시와보자

#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;

void dfs(vector<vector<bool>>& graph, vector<int>& parent, vector<bool>& visited) {
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i] && graph[stack.back()][i]) {
            visited[i] = true;
            parent[i] = stack.back();
            stack.push_back(i);
            dfs(graph, parent, visited);
        }
    }
    stack.pop_back();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<vector<bool>> graph(N, vector<bool>(N, false));
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x][y] = true;
        graph[y][x] = true;
    }
    
    vector<int> parent(N);
    parent[0] = -1;
    vector<bool> visited(N, false);
    visited[0] = true;

    stack.push_back(0);
    dfs(graph, parent, visited);

    for (int i = 1; i < N; i++) {
        cout << parent[i] + 1 << '\n';
    }



    return 0;
}