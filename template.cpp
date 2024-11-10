//
// Created by skshin on 2024. 11. 10..
//

// gold 5:  https://solved.ac/problems/level/11
// 1011:    https://www.acmicpc.net/problem/1011

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int A,B;
        cin >> A >> B;

        int result = A+B;
        cout << result << "\n";
    }

    return 0;
}
