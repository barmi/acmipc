//
// Created by skshin on 2025. 11. 18..
//

#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    uint32_t tree_heights[N];
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        cin >> tree_heights[i];
        if (tree_heights[i] > max_height) {
            max_height = tree_heights[i];
        }
    }
    int left = 0;
    int right = max_height;
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        uint64_t total_wood = 0;
        for (int i = 0; i < N; i++) {
            if (tree_heights[i] > mid) {
                total_wood += (tree_heights[i] - mid);
            }
        }

        if (total_wood >= M) {
            result = mid; // 가능한 최대 높이 갱신
            left = mid + 1; // 더 높은 높이 시도
        } else {
            right = mid - 1; // 낮은 높이 시도
        }
    }
    cout << result << "\n";

    return 0;
}