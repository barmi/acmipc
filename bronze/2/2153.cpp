//
// Created by skshin on 2025. 2. 20..
//

// https://www.acmicpc.net/problem/2153
// 마라톤 38-H

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            sum += s[i] - 'a' + 1;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            sum += s[i] - 'A' + 27;
        }
    }

    for (int i = 2; i < sum; i++)
    {
        if (sum % i == 0)
        {
            cout << "It is not a prime word.\n";
            return 0;
        }
    }
    cout << "It is a prime word.\n";

    return 0;
}
