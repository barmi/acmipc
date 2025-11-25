//
// Created by skshin on 2025. 11. 25..
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int board[N][2];
        int dp[N][3]; // 0: 첫 번째 행 선택, 1: 두 번째 행 선택, 2: 아무것도 선택 안 함
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[j][i];
            }
        }
        dp[0][0] = board[0][0];
        dp[0][1] = board[0][1];
        for (int i = 1; i < N; i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + board[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + board[i][1];
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        }
        int ans = max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2]));
        cout << ans << "\n";
    }

    return 0;
}