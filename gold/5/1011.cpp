//
// Created by skshin on 2024. 11. 10..
//

// gold 5:  https://solved.ac/problems/level/11
// 1011:    https://www.acmicpc.net/problem/1011

#include <iostream>
using namespace std;
/*
1:1
2:2     -> (4-1) / 2 = 1 + 1 = 2

//3:3

4:3

//5:4

6:4     -> (9-4) / 2 = 2 + 4 = 6
9:5
12:6    -> (16-9) / 2 = 3 + 9 = 12
16:7
20:8
25:9
30:10
36:11
42:12
49:13
56:14
64:15
72:16
81:17
90:18
100:19
110:20

 */
uint64_t get_sum_from_1_to_n(int n)
{
    return (uint64_t) n * (n + 1) / 2;
}

void make_all_inc_distance()
{
    for (int i = 1; i <= 10; i++)
    {
        uint64_t sum1 = get_sum_from_1_to_n(i);
        uint64_t sum2 = get_sum_from_1_to_n(i-1);
        cout << sum1 + sum2 << ":" << i + i - 1 << "\n";
        cout << sum1 + sum1 << ":" << i + i << "\n";
    }
}

int main()
{
//    make_all_inc_distance();
//    return 0;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
//    cin >> T;
    T = 1;

    while(T--)
    {
        int x, y;
//        cin >> x >> y;
        x = 0; y = 3;

        int distance = y - x;
        int sqrt_num = int(sqrt(distance));
        int near_square_num = sqrt_num * sqrt_num;
        int near_square_num_2 = (sqrt_num + 1) * (sqrt_num + 1);
        int mid_square_num = (near_square_num_2 - near_square_num) / 2 + near_square_num;
        int result = (distance == sqrt_num) ? sqrt_num * 2 - 1 : (sqrt_num + 1) * 2 - 1;

        if (distance >= mid_square_num)
        {
            ++result;
        }

        cout << result << "\n";
    }

    return 0;
}
