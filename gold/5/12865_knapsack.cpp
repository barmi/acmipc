//
// Created by skshin on 2025. 12. 10..
//

#include <iostream>

using namespace std;

#define MAX_N   (100+1)
#define MAX_W   (100000+1)

int N,K;
int W[MAX_N];
int V[MAX_N];
int dp[MAX_N][MAX_W];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++) // 경계치 0을 사용하기 위해서 값은 1부터 넣는다.
        cin >> W[i] >> V[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i] <= j) { // 담을 수 있는 경우,
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            } else {    // 담을 수 없는 경우,
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][K];

    return 0;
}
