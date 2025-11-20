//
// Created by skshin on 2025. 11. 20..
//

#include <iostream>
#include <deque>
#include <tuple>
#include <set>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    deque<tuple<int, int>> q;   // position, time
    set<int> visited;

    q.push_back(make_tuple(N, 0));
    visited.insert(N);

    while (!q.empty())
    {
        if (get<0>(q.front()) == K)
        {
            cout << get<1>(q.front()) << "\n";
            break;
        }
        int pos = get<0>(q.front());
        int time = get<1>(q.front());
        q.pop_front();

        if (pos - 1 >= 0 && visited.find(pos - 1) == visited.end())
        {
            visited.insert(pos - 1);
            q.push_back(make_tuple(pos - 1, time + 1));
        }
        if (visited.find(pos + 1) == visited.end())
        {
            visited.insert(pos + 1);
            q.push_back(make_tuple(pos + 1, time + 1));
        }
        if (pos * 2 <= 100000 && visited.find(pos * 2) == visited.end())
        {
            visited.insert(pos * 2);
            q.push_back(make_tuple(pos * 2, time + 1));
        }
    }

    return 0;
}
