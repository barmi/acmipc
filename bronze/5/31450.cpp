//
// Created by skshin on 2025. 2. 19..
//

// https://www.acmicpc.net/problem/31450

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, K;
    cin >> M >> K;

    if (M % K == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
