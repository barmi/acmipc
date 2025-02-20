//
// Created by skshin on 2025. 2. 20..
//

// https://www.acmicpc.net/problem/30999

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> yes(M, 0);
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        string answer;
        cin >> answer;

        int vote = 0;
        for (int j = 0; j < M; j++)
        {
            if (answer[j] == 'O')
            {
                vote++;
            }
        }
        if (vote > M/2)
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
