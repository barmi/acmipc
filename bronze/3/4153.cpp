//
// Created by skshin on 2025. 2. 15..
//

// https://www.acmicpc.net/problem/4153

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            break;
        }

        if (a * a + b * b == c * c ||
            a * a + c * c == b * b ||
            b * b + c * c == a * a)
        {
            cout << "right\n";
        }
        else
        {
            cout << "wrong\n";
        }
    }
}