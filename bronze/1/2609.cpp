//
// Created by skshin on 2025. 2. 21..
//

// https://www.acmicpc.net/problem/2609
// class 2

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int g = gcd(a, b);
    cout << g << "\n";
    cout << a * b / g << "\n";

    return 0;
}
