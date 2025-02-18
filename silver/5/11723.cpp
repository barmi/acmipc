//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/11723

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M;
    cin >> M;

    set<int> s;
    while (M--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "add")
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (cmd == "remove")
        {
            int x;
            cin >> x;
            s.erase(x);
        }
        else if (cmd == "check")
        {
            int x;
            cin >> x;
            cout << (s.find(x) != s.end()) << "\n";
        }
        else if (cmd == "toggle")
        {
            int x;
            cin >> x;
            if (s.find(x) != s.end())
            {
                s.erase(x);
            }
            else
            {
                s.insert(x);
            }
        }
        else if (cmd == "all")
        {
            for (int i = 1; i <= 20; i++)
            {
                s.insert(i);
            }
        }
        else if (cmd == "empty")
        {
            s.clear();
        }
    }

    return 0;
}
