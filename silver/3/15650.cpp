//
// Created by skshin on 2025. 4. 14..
//

#include <vector>
#include <iostream>

using namespace std;

void print_bt(vector<int>& arr, vector<bool>& visited, int depth, int n, int m, int last)
{
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = last + 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            print_bt(arr, visited, depth + 1, n, m, i);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    vector<bool> visited(m, false);
    print_bt(arr, visited, 0, n, m, 0);

    return 0;
}