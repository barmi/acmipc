#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int box[3][3] = {
    {1, 0, 0},
    {0, 0, 0},
    {0, 0, 1}
}; // 1: 익은 토마토, 0: 안 익은 토마토 (양 끝에 2개 존재)
int days[3][3];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

int main() {
    queue<pair<int,int>> q;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(box[i][j] == 1) {
                q.push({i, j}); // 모든 시작점을 큐에 삽입
                days[i][j] = 1;
            }
        }
    }

    int maxDays = 0;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        maxDays = max(maxDays, days[x][y]);

        for(int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=0 && nx<3 && ny>=0 && ny<3 && box[nx][ny]==0 && days[nx][ny]==0) {
                days[nx][ny] = days[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << "모두 익는 데 걸리는 시간: " << maxDays - 1 << "일" << endl;
    return 0;
}
