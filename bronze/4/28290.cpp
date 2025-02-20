//
// Created by skshin on 2025. 2. 20..
//

// https://www.acmicpc.net/problem/28290
// 마라톤 38-G

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    if (s == "fdsajkl;" || s == "jkl;fdsa") {
        cout << "in-out";
    }
    else if (s == "asdf;lkj" || s == ";lkjasdf") {
        cout << "out-in";
    }
    else if (s == "asdfjkl;") {
        cout << "stairs";
    }
    else if (s == ";lkjfdsa"){
        cout << "reverse";
    }
    else {
        cout << "molu";
    }
    cout << "\n";

    return 0;
}
