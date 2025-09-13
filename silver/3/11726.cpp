//
// Created by skshin on 2025. 9. 13..
//
// https://www.acmicpc.net/problem/11726
// 2xn 2타일링
/*
 * DP
 * n = 1: |, 1
 * n = 2: ||, ==, 2
 * n = 3: |||, ==|, |==, 3, dp[3] = dp[2] + dp[1]
 * n = 4: ||||, ==||, |==|, ||==, ====, 5, dp[4] = dp[3] + dp[2]
 *
 * dp[n] = dp[n-1] + dp[n-2]
 * dp[1] = 1
 * dp[2] = 2
 */
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	int n;
	cin >> n;
	cout << dp[n] << '\n';

	return 0;
}