//
// Created by skshin on 2025. 11. 20..
//

#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int g_x, g_y;
    int board[1000][1000];
    int dist[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int c;
            cin >> c;
            if (c == 2)
            {
                g_x = j;
                g_y = i;
                dist[j][i] = 0;
            }
            else
            {
                dist[j][i] = (c == 0) ? 0 : -1; // 갈수 없는 땅과 아직 방문 안한 땅 구분
                board[j][i] = c;
            }
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    deque<tuple<int, int>> q;  // x, y
    q.emplace_back(g_x, g_y);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop_front();
        int x = get<0>(t);
        int y = get<1>(t);
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (board[nx][ny] == 1 && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace_back(nx, ny);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[j][i] << " ";
        }
        cout << "\n";
    }
    return 0;
}