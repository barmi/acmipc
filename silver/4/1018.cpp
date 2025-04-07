//
// Created by skshin on 2025. 2. 22..
//

// https://www.acmicpc.net/problem/1018
// class 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int answer = 64;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = 0;
            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((x + y) % 2 == 0) {
                        if (board[x][y] != 'W') cnt++;
                    } else {
                        if (board[x][y] != 'B') cnt++;
                    }
                }
            }
            answer = min(answer, cnt);
            cnt = 0;
            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((x + y) % 2 == 0) {
                        if (board[x][y] != 'B') cnt++;
                    } else {
                        if (board[x][y] != 'W') cnt++;
                    }
                }
            }
            answer = min(answer, cnt);
        }
    }
    cout << answer;
    return 0;
}