#include <iostream>
#include <queue>

using namespace std;

int maze[5][5] = {
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1}
}; // 1: 길, 0: 벽 / (0,0)에서 (4,4)까지
int dist[5][5];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int main() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 4 && y == 4) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx>=0 && nx<5 && ny>=0 && ny<5 && maze[nx][ny]==1 && dist[nx][ny]==0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << "최단 거리: " << dist[4][4] << endl;
    return 0;
}
