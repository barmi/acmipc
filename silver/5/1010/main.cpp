//
// Created by skshin on 2024. 12. 26..
//

// silver 5: https://solved.ac/problems/level/6
// 1010:     https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    vector<vector<int>> dp(31, vector<int>(31, 0));
    for (int i = 1; i <= 30; i++)
    {
        dp[1][i] = i;
    }

    for (int i = 2; i <= 30; i++)
    {
        for (int j = i; j <= 30; j++)
        {
            for (int k = j; k >= i; k--)
            {
                dp[i][j] += dp[i - 1][k - 1];
            }
        }
    }

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }

    return 0;
}