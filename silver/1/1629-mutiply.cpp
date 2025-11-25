//
// Created by skshin on 2025. 11. 25..
//

#include <iostream>
#include <functional>
#include <cstdint>

using namespace std;

int main() {
    int64_t a, b, c;
    cin >> a >> b >> c;

    function<int64_t (int64_t)> pow = [&](int64_t x) -> int64_t {
        if (x == 0) {
            return 1;
        } else if (x == 1) {
            return a % c;
        }

        if (x % 2 == 0) {
            int64_t pow_half = pow(x / 2);
            return pow_half * pow_half % c;
        } else {
            return a * pow(x - 1) % c;
        }
    };
    cout << pow(b) << endl;
}