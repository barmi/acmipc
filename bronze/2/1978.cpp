//
// Created by skshin on 2025. 2. 19..
//

// https://www.acmicpc.net/problem/1978

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<bool> is_prime(1001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(1000); i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (is_prime[num])
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
