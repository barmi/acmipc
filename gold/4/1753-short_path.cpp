//
// Created by skshin on 2025. 12. 17..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
typedef pair<int,int> pii;

vector<int> dijkstra(int start, int V, vector<vector<pii>>& graph)
{
    vector<int> dist(V + 1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<pii>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dist = dijkstra(K, V, graph);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;

}