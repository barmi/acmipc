//
// Created by skshin on 2025. 11. 25..
//

#include <iostream>
#include <unordered_map>
#include <functional>

using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<char,pair<char,char>> tree;
    for (int i = 0; i < N; i++) {
        char a,b, c;
        cin >> a >> b >> c;
        tree[a] = {b,c};
    }
    // 전위 순회
    function<void(char)> preorder = [&](char node) {
        if (node == '.') return;
        cout << node;
        preorder(tree[node].first);
        preorder(tree[node].second);
    };
    preorder('A');
    cout << '\n';

    // 중위 순회
    function<void(char)> inorder = [&](char node) {
        if (node == '.') return;
        inorder(tree[node].first);
        cout << node;
        inorder(tree[node].second);
    };
    inorder('A');
    cout << '\n';

    // 후위 순회
    function<void(char)> postorder = [&](char node) {
        if (node == '.') return;
        postorder(tree[node].first);
        postorder(tree[node].second);
        cout << node;
    };
    postorder('A');
    cout << '\n';

    return 0;
}