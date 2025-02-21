//
// Created by skshin on 2025. 2. 21..
//

// https://www.acmicpc.net/problem/10814
// class 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Member
{
    int age;
    string name;
    int order;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Member> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].age >> v[i].name;
        v[i].order = i;
    }

    sort(v.begin(), v.end(), [](const Member &a, const Member &b) {
        if (a.age == b.age) {
            return a.order < b.order;
        }
        return a.age < b.age;
    });

    for (int i = 0; i < N; i++)
    {
        cout << v[i].age << " " << v[i].name << "\n";
    }

    return 0;
}