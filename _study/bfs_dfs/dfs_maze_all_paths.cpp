#include <iostream>
#include <vector>

using namespace std;

int maze[3][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
}; // 1은 벽, 0은 통로
bool v[3][3];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int pathCount = 0;

void findPaths(int x, int y) {
    if (x == 2 && y == 2) { // 도착 지점 (2,2)
        pathCount++;
        return;
    }
    v[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx>=0 && nx<3 && ny>=0 && ny<3 && maze[nx][ny]==0 && !v[nx][ny]) {
            findPaths(nx, ny);
        }
    }
    v[x][y] = false; // 다른 경로 탐색을 위해 방문 해제
}

int main() {
    findPaths(0, 0);
    cout << "미로 탈출 가능한 총 경로 수: " << pathCount << endl;
    return 0;
}
