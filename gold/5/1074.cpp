//
// Created by skshin on 2025. 11. 20..
//

#include <iostream>
#include <cstdint>

using namespace std;

uint64_t find_square(int N, uint64_t r, uint64_t c)
{
    if (N == 0)
        return 0;

    uint64_t half = 1ULL << (N - 1);
    uint64_t quadrant_size = half * half;

    if (r < half && c < half)
    {
        // 1st quadrant
        return find_square(N - 1, r, c);
    }
    else if (r < half && c >= half)
    {
        // 2nd quadrant
        return quadrant_size + find_square(N - 1, r, c - half);
    }
    else if (r >= half && c < half)
    {
        // 3rd quadrant
        return 2 * quadrant_size + find_square(N - 1, r - half, c);
    }
    else
    {
        // 4th quadrant
        return 3 * quadrant_size + find_square(N - 1, r - half, c - half);
    }
}

int main()
{
    int N;
    uint64_t r, c;
    cin >> N >> r >> c;
    cout << find_square(N, r, c) << "\n";
    return 0;
}