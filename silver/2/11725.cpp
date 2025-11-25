//
// Created by skshin on 2025. 11. 24..
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;


int p[100001];

int main()
{
    int N;
    cin >> N;
    unordered_map<int,vector<int>> graph(N);
    for (int i = 0; i < N-1; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    deque<int> dq;
    dq.push_back(1);
    while (!dq.empty())
    {
        int now = dq.front();
        dq.pop_front();
        for (int next : graph[now])
        {
            if (p[next] == 0)
            {
                p[next] = now;
                dq.push_back(next);
            }
        }
    }
    for (int i = 2; i <= N; i++)
        cout << p[i] << "\n";
    return 0;
}