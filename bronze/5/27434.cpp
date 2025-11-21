//
// Created by skshin on 2025. 11. 21..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

// 큰 수를 BASE 진법으로 표현하여 곱셈 최적화
const ll BASE = 1000000000; // 10^9

vll multiply(const vll& a, const vll& b) {
    vll result(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); i++) {
        ll carry = 0;
        for (int j = 0; j < b.size(); j++) {
            ll prod = a[i] * b[j] + result[i + j] + carry;
            result[i + j] = prod % BASE;
            carry = prod / BASE;
        }
        if (carry > 0) {
            result[i + b.size()] += carry;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

vll factorial(int start, int end) {
    if (start > end) {
        return {1};
    }
    if (start == end) {
        return {(ll)start};
    }

    int mid = (start + end) / 2;
    return multiply(factorial(start, mid), factorial(mid + 1, end));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    if (N == 0 || N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    vll result = factorial(2, N);

    // 가장 높은 자리 출력
    cout << result.back();

    // 나머지 자리는 9자리로 맞춰서 출력
    for (int i = result.size() - 2; i >= 0; i--) {
        cout.width(9);
        cout.fill('0');
        cout << result[i];
    }
    cout << '\n';

    return 0;
}