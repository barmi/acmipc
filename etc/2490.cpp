//
// Created by skshin on 2025. 2. 11..
//
// https://www.acmicpc.net/problem/2490

#include <cstdio>

using namespace std;

int main()
{
    char r[3];
    for (int n = 0; n < 3; n++) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int yut;
            scanf("%d", &yut);
            if (yut == 0) {
                count++;
            }
        }
//        printf("%c\n", 'A' + ((count == 0) ? 4 : count-1) );
        r[n] = 'A' + ((count == 0) ? 4 : count-1);
    }
    for (int i = 0; i < 3; i++) {
        printf("%c\n", r[i]);
    }
    return 0;
}