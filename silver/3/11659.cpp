//
// Created by skshin on 2025. 4. 7..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int64_t> sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }
    int ni, nj;
    for (int i = 0; i < m; i++) {
        cin >> ni >> nj;
        cout << sum[nj] - sum[ni-1] << '\n';
    }

    return 0;
}
