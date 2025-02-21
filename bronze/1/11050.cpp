//
// Created by skshin on 2025. 2. 21..
//

// https://www.acmicpc.net/problem/11050
// class 2

#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    cout << factorial(N) / (factorial(K) * factorial(N - K)) << "\n";

    return 0;
}
