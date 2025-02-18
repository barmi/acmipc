//
// Created by skshin on 2025. 2. 11..
//
// bronze 1:  https://solved.ac/problems/level/5
// 1037:    https://www.acmicpc.net/problem/1037

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int min_value = 1000001;
    int max_value = 0;
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        min_value = min(min_value, value);
        max_value = max(max_value, value);
    }

    cout << min_value * max_value << "\n";

    return 0;
}