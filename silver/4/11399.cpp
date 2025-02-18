//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    int sum = 0;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        sum += P[i];
        result += sum;
    }

    cout << result << "\n";

    return 0;
}
