//
// Created by skshin on 2025. 2. 16..
//

// https://www.acmicpc.net/problem/1330

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    if (A < B)
    {
        cout << "<\n";
    }
    else if (A > B)
    {
        cout << ">\n";
    }
    else
    {
        cout << "==\n";
    }

    return 0;
}