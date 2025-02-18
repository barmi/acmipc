//
// Created by skshin on 2025. 2. 11..
//
// diamond 5:  https://solved.ac/problems/level/21
// 1557:       https://www.acmicpc.net/problem/1557

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

using ll = long long;

deque<bool> sieve()
{
    deque<bool> p(40558, true);
    p[0] = p[1] = false;
    for (int i = 2; i < p.size(); ++i) {
        if (p[i]) {
            for (int j = 2 * i; j < p.size(); j += i) {
                p[j] = false;
            }
        }
    }
    return p;
}

vector<int> P;

ll solve(ll X, int idx, ll val)
{
    ll ret = X / (val * val);
    for (int i = idx; i < P.size(); ++i) {
        ll y = val * P[i];
        if (X < y * y) {
            break;
        }
        ret -= solve(X, i + 1, y);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<bool> p = sieve();
    for (int i = 2; i < p.size(); ++i) {
        if (p[i]) {
            P.push_back(i);
        }
    }
    int K{};
    cin >> K;
    ll lo = 0, hi = 2e9;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll s = solve(mid, 0, 1);
        if (s < K) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << hi << "\n";
    return 0;
}