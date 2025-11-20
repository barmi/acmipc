//
// Created by skshin on 2025. 11. 20..
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> m(N);   // (end, start)
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        m[i] = make_pair(b, a);
    }
    sort(m.begin(), m.end());
    int count = 0;
    int last_end_time = 0;
    for (auto& p : m)
    {
        auto [end, start] = p;
        if (start >= last_end_time)
        {
            last_end_time = end;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
