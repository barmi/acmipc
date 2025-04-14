//
// Created by skshin on 2025. 4. 14..
//

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int64_t> x(n + 1);
    vector<int64_t> y(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (x[i] * y[i+1]) - (x[i+1] * y[i]);
    }
    ans = abs(ans);
    ans = ans / 2.0;
    cout << fixed;
    cout.precision(1);
    cout << ans << '\n';

    return 0;
}