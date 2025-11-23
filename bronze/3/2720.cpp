//
// Created by skshin on 2025. 11. 23..
//

#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int c_25 = N / 25;
        N -= c_25 * 25;
        int c_10 = N / 10;
        N -= c_10 * 10;
        int c_5 = N / 5;
        N -= c_5 * 5;
        int c_1 = N;

        cout << c_25 << " " << c_10 << " " << c_5 << " " << c_1 << "\n";
    }
    return 0;
}