//
// Created by skshin on 2025. 11. 27..
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    auto len_s1 = s1.size();
    auto len_s2 = s2.size();
    int dp[len_s1 + 1][len_s2 + 1];
    memset(dp, 0, sizeof(dp));
    int max_len = 0;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            max_len = max(max_len, dp[i][j]);
        }
    }
    cout << max_len << "\n";

    return 0;
}