//
// Created by skshin on 2024. 12. 26..
//

// bronze 1:  https://solved.ac/problems/level/5
// 1011:    https://www.acmicpc.net/problem/1032

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    string answer = v[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (answer[j] != v[i][j])
            {
                answer[j] = '?';
            }
        }
    }

    cout << answer << "\n";

    return 0;
}

