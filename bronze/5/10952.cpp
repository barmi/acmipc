//
// Created by skshin on 2025. 2. 17..
//

// https://www.acmicpc.net/problem/10952

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    while (cin >> A >> B)
    {
        if (A == 0 && B == 0)
        {
            break;
        }
        cout << A + B << "\n";
    }

    return 0;
}
