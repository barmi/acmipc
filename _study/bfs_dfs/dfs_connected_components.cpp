#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(int curr) {
    visited[curr] = true;
    for (int next : adj[curr]) {
        if (!visited[next]) dfs(next);
    }
}

int main() {
    // 샘플 데이터: 1-2-3 (덩어리1), 4-5 (덩어리2), 6 (덩어리3)
    adj[1]={2}; adj[2]={1,3}; adj[3]={2};
    adj[4]={5}; adj[5]={4};
    // 6은 고립된 노드

    int components = 0;
    for (int i = 1; i <= 6; i++) {
        if (!visited[i]) {
            dfs(i);
            components++; // DFS가 시작되는 횟수가 곧 덩어리의 개수
        }
    }
    cout << "연결 요소 개수: " << components << endl; // 출력: 3
    return 0;
}
