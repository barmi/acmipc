//
// Created by skshin on 2025. 11. 21..
//

#include <iostream>
#include <deque>

using namespace std;

int box[1000][1000];
int visited[1000][1000]; // day when visit

int main()
{
    int c, r;
    cin >> c >> r; // M, N
    deque<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push_back({i, j});
                visited[i][j] = 1;
            }
        }
    }

    int days = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        auto [y, x] = q.front();
        days = visited[y][x];
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx] && box[ny][nx] == 0)
            {
                visited[ny][nx] = days + 1;
                box[ny][nx] = 1;
                q.push_back({ny, nx});
            }
        }
    }

    // find 0
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (box[i][j] == 0)
            {
                cout << -1 << "\n";
                return 0;
            }

    cout << days - 1 << "\n";
    return 0;
}