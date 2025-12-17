//
// Created by skshin on 2025. 12. 17..
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int visited[100001] = {0,};
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, N});
    while (!pq.empty())
    {
        auto [time, pos] = pq.top(); pq.pop();
        if (visited[pos]) continue;
        visited[pos] = 1;

        if (pos == K) {
            cout << time << "\n";
            return 0;
        }
        if (pos > 0 && !visited[pos - 1]) pq.push({time + 1, pos - 1});
        if (pos < 100000 && !visited[pos + 1]) pq.push({time + 1, pos + 1});
        if (pos * 2 <= 100000 && !visited[pos * 2]) pq.push({time, pos * 2});
    }

}