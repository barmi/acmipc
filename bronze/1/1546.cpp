//
// Created by skshin on 2025. 2. 21..
//

// https://www.acmicpc.net/problem/1546

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    double max_score = 0;
    double sum_score = 0;
    for (int i = 0; i < N; i++)
    {
        double score;
        cin >> score;

        if (score > max_score)
        {
            max_score = score;
        }

        sum_score += score;
    }

    cout << fixed;
    cout.precision(2);
    cout << sum_score / max_score * 100 / N << "\n";

    return 0;
}
