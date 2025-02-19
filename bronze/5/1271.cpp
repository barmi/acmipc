//
// Created by skshin on 2025. 2. 18..
//

// https://www.acmicpc.net/problem/1271

#include <iostream>
#include <string>

using namespace std;

__int128 stringToInt128(const string &str) {
    __int128 result = 0;
    for (char c : str) {
        result = result * 10 + (c - '0');
    }
    return result;
}

void printInt128(__int128 num) {
    if (num == 0) {
        cout << "0";
        return;
    }
    string result;
    while (num > 0) {
        result += (num % 10) + '0';
        num /= 10;
    }
    reverse(result.begin(), result.end());
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string N, M;
    cin >> N >> M;

    __int128 n = stringToInt128(N);
    __int128 m = stringToInt128(M);

    __int128 q = n / m;
    __int128 r = n % m;

    printInt128(q);
    cout << "\n";
    printInt128(r);
    cout << "\n";

    return 0;
}