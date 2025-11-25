//
// Created by skshin on 2025. 11. 24..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #define USE_DFS_RECURSION

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    // 길이 M의 수열을 만들되, 같은 수가 여러 번 주어질 수 있으므로
    // 같은 깊이에서 동일한 값을 중복 선택하지 않도록 한다.

#if defined(USE_DFS_RECURSION)
    vector<int> path(M);
    vector<int> used(N, 0);

    function<void(int)> dfs = [&](int depth) {
        if (depth == M)
        {
            for (int i = 0; i < M; i++)
            {
                if (i) cout << ' ';
                cout << path[i];
            }
            cout << '\n';
            return;
        }

        int prev = 0;
        for (int i = 0; i < N; i++)
        {
            if (used[i]) continue;
            if (arr[i] == prev) continue; // 같은 깊이에서 같은 값 중복 방지

            used[i] = 1;
            path[depth] = arr[i];
            prev = arr[i];
            dfs(depth + 1);
            used[i] = 0;
        }
    };

    dfs(0);
#else
    // 여기에 recursion이 아닌 형태로 dfs 구현
    // 스택 프레임을 수동으로 시뮬레이션한다.
    // 각 깊이(depth)에 대해 다음 시도할 인덱스(idx[depth])와
    // 같은 깊이에서의 중복 방지를 위한 prev(값 기준) 상태를 유지한다.
    vector<int> path(M);
    vector<int> used(N, 0);

    // 다음에 시도할 시작 인덱스(각 깊이별)
    vector<int> idx(max(1, M), 0);
    // 같은 깊이에서 마지막으로 선택(시도)한 값 추적
    vector<int> prevVal(max(1, M), 0);
    vector<int> hasPrev(max(1, M), 0); // 0 = 없음, 1 = 있음
    // 해당 깊이에서 마지막으로 선택된 인덱스(백트래킹 시 unuse용)
    vector<int> chosen(max(1, M), -1);

    int depth = 0;
    while (true)
    {
        if (depth == M)
        {
            // 출력
            for (int i = 0; i < M; i++)
            {
                if (i) cout << ' ';
                cout << path[i];
            }
            cout << '\n';

            // 한 단계 backtrack
            depth--;
            if (depth < 0) break; // 모든 탐색 종료

            int ci = chosen[depth];
            used[ci] = 0;
            // 부모 깊이에서 다음 후보로 진행
            idx[depth] = ci + 1;
            // prev는 유지(같은 깊이에서 동일 값 중복 방지 지속)
            continue;
        }

        bool advanced = false;
        for (int i = idx[depth]; i < N; ++i)
        {
            if (used[i]) continue;
            if (hasPrev[depth] && arr[i] == prevVal[depth]) continue; // 같은 깊이에서 같은 값 중복 방지

            // 선택
            used[i] = 1;
            path[depth] = arr[i];
            chosen[depth] = i;
            prevVal[depth] = arr[i];
            hasPrev[depth] = 1;

            // 다음 깊이 준비
            depth++;
            if (depth < M)
            {
                idx[depth] = 0;
                hasPrev[depth] = 0;
                // prevVal[depth]는 의미 없음(다음에 설정됨)
            }
            advanced = true;
            break;
        }

        if (advanced) continue;

        // 더 이상 선택할 후보가 없으므로 backtrack
        if (depth == 0)
        {
            // 최상위에서도 더 이상 없음 → 종료
            break;
        }

        // 현재 깊이 상태 초기화(다시 내려올 때를 대비)
        idx[depth] = 0;
        hasPrev[depth] = 0;

        depth--;
        int ci = chosen[depth];
        used[ci] = 0;
        idx[depth] = ci + 1; // 부모 깊이에서 다음 후보로 진행
        // prev는 유지
    }
    
#endif
}
