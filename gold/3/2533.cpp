//
// Created by skshin on 2025. 5. 2..
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[1000001];
int64_t dp[1000001][2];
bool visited[1000001];

void find(int node)
{
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;

    for (int child : tree[node]) {
        if (!visited[child]) {
            find(child);
            dp[node][0] += dp[child][1];
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    find(1);
    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}