//
// Created by skshin on 2025. 2. 11..
//
// diamond 5:  https://solved.ac/problems/level/21
// 1557:       https://www.acmicpc.net/problem/1557

#include <iostream>
#include <set>
#include <cmath>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    set<uint64_t> squares;
    int K2 = K * 2;
    int Kh = K / 2 + 1;
    for (uint64_t i = 2; i <= sqrt(K2)*2; ++i) {
        squares.insert(i * i);

        if (squares.size() > K) {
            break;
        }
        for (int j = 2; j <= sqrt(K2)*2; ++j) {
            if (i * i * j > Kh) {
                break;
            }
            squares.insert(i * i * j);
        }
    }

    int count = 0;
    for (auto s: squares) {
        if (s > K + count) {
            break;
        }
        count++;
    }
    cout << K + count << "\n";

    return 0;
}