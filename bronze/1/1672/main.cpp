//
// Created by skshin on 2025. 2. 11..
//
// bronze 1:  https://solved.ac/problems/level/5
// 1672:    https://www.acmicpc.net/problem/1672

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<char,map<char,char>> dna_map = {
    {'A', {{'A', 'A'}, {'G', 'C'}, {'C', 'A'}, {'T', 'G'}}},
    {'G', {{'A', 'C'}, {'G', 'G'}, {'C', 'T'}, {'T', 'A'}}},
    {'C', {{'A', 'A'}, {'G', 'T'}, {'C', 'C'}, {'T', 'G'}}},
    {'T', {{'A', 'G'}, {'G', 'A'}, {'C', 'G'}, {'T', 'T'}}}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string dna;
    cin >> dna;
    std::reverse(dna.begin(), dna.end());

    for (int i = 0; i < N-1; i++)
    {
        char a = dna[i];
        char b = dna[i+1];
        dna[i+1] = dna_map[a][b];
    }

    cout << dna[N-1] << "\n";
}
