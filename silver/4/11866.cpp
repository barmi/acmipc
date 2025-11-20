//
// Created by skshin on 2025. 11. 21..
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> persons(N);
    vector<int> seq;
    int remove_count = 0;
    int cur_pos = -1;
    while (remove_count < N)
    {
        int step = 0;
        while (step < K)
        {
            cur_pos = (cur_pos + 1) % N;
            if (persons[cur_pos] == 0)
                step++;
        }
        persons[cur_pos] = 1;
        seq.push_back(cur_pos + 1);
        remove_count++;
    }
    cout << "<";
    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i];
        if (i != seq.size() - 1)
            cout << ", ";
    }
    cout << ">" << endl;
    return 0;
}