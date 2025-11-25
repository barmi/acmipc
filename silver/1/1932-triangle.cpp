//
// Created by skshin on 2025. 11. 25..
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N;
    cin >> N;
    int triangle[N][N];
    int dp[N][N];
    memset(dp, 0, sizeof(dp));
    int max_value = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
            if (i == 0) dp[i][j] = triangle[i][j];
            else {
                if (j == 0) dp[i][j] = triangle[i][j] + dp[i-1][j];
                else if (j == i) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                else dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            }
            max_value = max(max_value, dp[i][j]);
        }
    }
    cout << max_value << "\n";
}