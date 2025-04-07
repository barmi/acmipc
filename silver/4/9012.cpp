//
// Created by skshin on 2025. 3. 17..
//

// https://www.acmicpc.net/problem/9012

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            else cnt--;
            if (cnt < 0) break;
        }
        cout << (cnt == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
