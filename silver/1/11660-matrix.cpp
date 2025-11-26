//
// Created by skshin on 2025. 11. 26..
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int matrix[N+1][N+1];
    memset(matrix, 0, sizeof(matrix));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int value;
            cin >> value;
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + value;
        }
    }
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        sum = matrix[x2][y2] - matrix[x1-1][y2] - matrix[x2][y1-1] + matrix[x1-1][y1-1];
        cout << sum << '\n';
    }

    return 0;
}