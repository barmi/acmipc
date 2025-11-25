//
// Created by skshin on 2025. 11. 25..
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cost[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    int dp[N][3];
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            dp[i][0] = cost[i][0];
            dp[i][1] = cost[i][1];
            dp[i][2] = cost[i][2];
        }
        else {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }
    }
    cout << min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2])) << "\n";

    return 0;
}