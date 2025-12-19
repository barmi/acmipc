#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수 설정
vector<int> graph[10]; // 정점 1~9 사용
bool visited[10];      

// DFS (재귀 구현)
// 깊이 우선 탐색: 한 노드에서 연결된 경로를 따라 끝까지 파고듭니다.
void dfs(int current) {
    visited[current] = true; // 현재 노드 방문 처리
    cout << current << " ";

    for (int next : graph[current]) {
        if (!visited[next]) { // 방문하지 않은 인접 노드가 있다면
            dfs(next);        // 더 깊이 이동 (재귀 호출)
        }
    }
}

// BFS (큐 구현)
// 너비 우선 탐색: 시작점으로부터 가까운 노드들을 먼저 방문합니다.
void bfs(int start) {
    queue<int> q;
    q.push(start);           // 시작 노드를 큐에 삽입
    visited[start] = true;   // 방문 처리

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true; // 큐에 넣을 때 방문 처리 (중복 방지)
                q.push(next);
            }
        }
    }
}

void reset_visited() {
    for (int i = 0; i < 10; i++) visited[i] = false;
}

int main() {
    /* 
       샘플 그래프 구성 (무방향)
       1 -- 2 -- 5
       |    |
       3 -- 4
       |    |
       6 -- 7 -- 8
            |
            9
    */
    graph[1] = {2, 3};
    graph[2] = {1, 4, 5};
    graph[3] = {1, 4, 6};
    graph[4] = {2, 3, 7};
    graph[5] = {2};
    graph[6] = {3, 7};
    graph[7] = {4, 6, 8, 9};
    graph[8] = {7};
    graph[9] = {7};

    // 방문 순서를 일정하게 하기 위해 인접 리스트 정렬
    for (int i = 1; i <= 9; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    cout << "=== DFS 탐색 (시작: 1) ===" << endl;
    reset_visited();
    dfs(1);
    cout << "\n\n";

    cout << "=== BFS 탐색 (시작: 1) ===" << endl;
    reset_visited();
    bfs(1);
    cout << "\n";

    return 0;
}
