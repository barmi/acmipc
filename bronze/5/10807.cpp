//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/10807

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(201, 0);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v[n + 100]++;
    }

    int V;
    cin >> V;

    cout << v[V + 100] << "\n";

    return 0;
}
