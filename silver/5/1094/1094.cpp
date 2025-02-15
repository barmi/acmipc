//
// Created by skshin on 2025. 2. 15..
//

// https://www.acmicpc.net/problem/1094

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int X;
    cin >> X;

    int bit_count = 0;
    for (int i = 0; i < 7; i++)
    {
        if (X & (1 << i))
        {
            bit_count++;
        }
    }

    cout << bit_count << "\n";
}