//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    set<string> s;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        s.insert(name);
    }

    set<string> result;
    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;
        if (s.find(name) != s.end())
        {
            result.insert(name);
        }
    }

    cout << result.size() << "\n";
    for (auto name: result)
    {
        cout << name << "\n";
    }

    return 0;
}
