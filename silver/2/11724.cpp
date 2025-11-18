//
// Created by skshin on 2025. 11. 18..
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

void bfs(int start_node, map<int, vector<int>> &graph, set<int> &visited)
{
    deque<int> queue;
    queue.push_back(start_node);

    while (!queue.empty())
    {
        int current = queue.front();
        queue.erase(queue.begin());

        for (int neighbor : graph[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                queue.push_back(neighbor);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    map<int, vector<int>> graph; // small, vector(large)
    set<int> visited;

    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int chunk_count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited.find(i) == visited.end())
        {
            chunk_count++;
            visited.insert(i);
            if (graph.find(i) != graph.end()) // has edges
            {
                bfs(i, graph, visited);
            }
        }
    }
    cout << chunk_count /*+ (N - visited.size())*/ << "\n";
    return 0;
}