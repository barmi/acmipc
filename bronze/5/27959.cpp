//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/27959

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    if (N*100 >= M)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
