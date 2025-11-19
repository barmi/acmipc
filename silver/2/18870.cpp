//
// Created by skshin on 2025. 11. 19..
//
#include <iostream>
#include <algorithm>

using namespace std;

int p[1000000]; // 좌표
int s[1000000]; // 좌표의 소팅된 값
int u[1000000]; // 중복 제거된 값

int main()
{

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
        s[i] = p[i];
    }
    // s를 오름차순 정렬
    sort(s, s + N);
    // 중복 제거
    int pos_u = 0;
    int unique_count = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            u[pos_u++] = s[i];
            unique_count++;
        }
    }
    // 원래 좌표의 각 값에 대해 중복 제거된 배열에서의 인덱스 찾기
    for (int i = 0; i < N; i++)
    {
        int low_index = lower_bound(u, u + unique_count, p[i]) - u;
        cout << low_index << " ";
    }
    cout << "\n";
    return 0;
}