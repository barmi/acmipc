//
// Created by skshin on 2025. 2. 11..
//

// bronze 1:  https://solved.ac/problems/level/5?page=17
// 32953:    https://www.acmicpc.net/problem/32953

#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    map<int,int> count; // 학번, 수강횟수
    for (int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            int st;
            scanf("%d", &st);
            count[st]++;
        }
    }

    int total_count = 0;
    for (auto i: count)
    {
        if (i.second >= M)
        {
            total_count++;
        }
    }

    printf("%d\n", total_count);
}