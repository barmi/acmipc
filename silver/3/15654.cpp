//
// Created by skshin on 2025. 4. 14..
//

#include <vector>
#include <iostream>

using namespace std;

void print_bt(vector<int>& value, vector<int>& arr, vector<bool>& visited, int depth, int n, int m, int last)
{
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << value[arr[i]-1] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            print_bt(value, arr, visited, depth + 1, n, m, i);
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
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    sort(value.begin(), value.end());

    print_bt(value, arr, visited, 0, n, m, 0);

    return 0;
}