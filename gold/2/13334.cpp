//
// Created by skshin on 2025. 5. 2..
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> dist;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dist.push_back({a, b});
    }
    int d;
    cin >> d;
    sort(dist.begin(), dist.end());

    return 0;
}