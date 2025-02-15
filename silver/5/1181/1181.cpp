//
// Created by skshin on 2025. 2. 15..
//

// https://solved.ac/problems/level/6
// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string words[20000];
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    sort(words, words + N, [](const string& a, const string& b) {
        if (a.size() == b.size())
        {
            return a < b;
        }
        return a.size() < b.size();
    });

    for (int i = 0; i < N; i++)
    {
        if (i > 0 && words[i] == words[i-1])
        {
            continue;
        }
        cout << words[i] << "\n";
    }

    return 0;
}