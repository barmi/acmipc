//
// Created by skshin on 2025. 2. 19..
//

// https://www.acmicpc.net/problem/30802

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, S[6], T, P;
    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> S[i];
    }
    cin >> T >> P;

    int sum_min_t = 0;
    for (int i = 0; i < 6; i++)
    {
        int min_t = (S[i] + T - 1) / T;
        sum_min_t += min_t;
    }

    cout << sum_min_t << "\n";
    cout << N  / P << " " << N % P << "\n";

    return 0;
}