//
// Created by skshin on 2025. 2. 11..
//
// platinum 5:  https://solved.ac/problems/level/13
// 1019:        https://www.acmicpc.net/problem/1019

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int count[10] = {0,};

    auto add_count = [&](int num, int factor) {
        while (num > 0) {
            count[num % 10] += factor;
            num /= 10;
        }
    };

    int start = 1;
    int factor = 1;
    while (start <= N) {
        while (N % 10 != 9 && start <= N) {
            add_count(N, factor);
            N--;
        }
        if (N < start) break;
        while (start % 10 != 0 && start <= N) {
            add_count(start, factor);
            start++;
        }
        start /= 10;
        N /= 10;
        for (int i = 0; i < 10; i++) {
            count[i] += (N - start + 1) * factor;
        }
        factor *= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << count[i] << " ";
    }
    cout << "\n";

    return 0;
}