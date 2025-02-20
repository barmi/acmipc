//
// Created by skshin on 2025. 2. 20..
//

// https://www.acmicpc.net/problem/1259
// class 2

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string s;
        cin >> s;

        if (s == "0")
        {
            break;
        }

        bool is_palindrome = true;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                is_palindrome = false;
                break;
            }
        }

        if (is_palindrome)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}
