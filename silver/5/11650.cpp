//
// Created by skshin on 2025. 2. 21..
//

// https://www.acmicpc.net/problem/11650
// class 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Point> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end(), [](const Point &a, const Point &b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    });

    for (int i = 0; i < N; i++)
    {
        cout << v[i].x << " " << v[i].y << "\n";
    }

    return 0;
}
