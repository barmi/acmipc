//
// Created by skshin on 2025. 2. 15..
//

// https://solved.ac/problems/level/7
// https://www.acmicpc.net/problem/1015

/*
 3
 2 3 1
 -> 1 2 0

    p[0] = 1
    p[1] = 2
    p[2] = 0

    a[0] = 2
    a[1] = 3
    a[2] = 1

    b[p[0]] = a[0] = 2 = b[1]
    b[p[1]] = a[1] = 3 = b[2]
    b[p[2]] = a[2] = 1 = b[0]

    b = [ 1, 2, 3 ]

    -------------------

    a = [ 2, 3, 1 ]
    b = [ 1, 2, 3 ]
    b[p[0]] = a[0] = 2 = b[1], p[0] = 1
    b[p[1]] = a[1] = 3 = b[2], p[1] = 2
    b[p[2]] = a[2] = 1 = b[0], p[2] = 0

    -------------------

    a = [ 4, 1, 6, 1, 3, 6, 1, 4 ]
    b = [ 1, 1, 1, 3, 4, 4, 6, 6 ]
    b[p[0]] = a[0] = 4 = b[4], p[0] = 4
    b[p[1]] = a[1] = 1 = b[0], p[1] = 0 // 1이 0,1,2에 있으므로, 첫번째 0을 사용
    b[p[2]] = a[2] = 6 = b[6], p[2] = 6
    b[p[3]] = a[3] = 1 = b[1], p[3] = 1 // 1이 0,1,2에 있으므로, 두번째 1을 사용
    b[p[4]] = a[4] = 3 = b[3], p[4] = 3
    b[p[5]] = a[5] = 6 = b[6], p[5] = 6 // 6이 6,7에 있으므로, 첫번째 6을 사용
    b[p[6]] = a[6] = 1 = b[1], p[6] = 1 // 1이 0,1,2에 있으므로, 세번째 1을 사용
    b[p[7]] = a[7] = 4 = b[4], p[7] = 4 // 4가 4,5에 있으므로, 첫번째 4를 사용

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    vector<int> P(N);
    vector<bool> used_B(N, false);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i] == B[j] && !used_B[j])
            {
                P[i] = j;
                used_B[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << P[i] << " ";
    }
    cout << "\n";

    return 0;
}