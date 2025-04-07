//
// Created by skshin on 2025. 4. 7..
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int get_bfs_count(vector<set<int>>& arr, vector<bool>& visited, int start)
{
    int count = 0;
    vector<int> queue;
    queue.push_back(start);
    visited[start] = true;

    while (!queue.empty()) {
        int current = queue.back();
        queue.pop_back();
        count++;

        for (int neighbor : arr[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<set<int>> arr(n+1);
    vector<bool> visited(n+1, false);

    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    int count = get_bfs_count(arr, visited, 1);
    cout << count - 1 << '\n';

    return 0;
}