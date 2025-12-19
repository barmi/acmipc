#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10];
int color[10]; // 0: 미방문, 1: 빨강, 2: 파랑

int main() {
    // 샘플: 1-2-3 (이분 그래프 가능)
    adj[1]={2}; adj[2]={1,3}; adj[3]={2};
    
    queue<int> q;
    q.push(1);
    color[1] = 1;
    bool isBipartite = true;

    while(!q.empty() && isBipartite) {
        int curr = q.front(); q.pop();
        for(int next : adj[curr]) {
            if(color[next] == 0) {
                color[next] = 3 - color[curr]; // 1이면 2, 2면 1로 칠함
                q.push(next);
            } else if(color[next] == color[curr]) {
                isBipartite = false; // 같은 색이 인접하면 탈락
            }
        }
    }
    cout << "이분 그래프 여부: " << (isBipartite ? "YES" : "NO") << endl;
    return 0;
}
