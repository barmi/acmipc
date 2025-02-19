//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/4101

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int A, B;
        cin >> A >> B;

        if (A == 0 && B == 0)
        {
            break;
        }

        if (A > B)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
