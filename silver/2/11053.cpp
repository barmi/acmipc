//
// Created by skshin on 2025. 11. 24..
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int n[1001];

    for (int i = 0; i < N; i++)
        cin >> n[i];

    int dp[1001] = {0};
    dp[1] = 1;
    int max = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (n[i-1] > n[j-1] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                max = max < dp[i] ? dp[i] : max;
            }
        }
    }
    cout << max << "\n";

    return 0;
}