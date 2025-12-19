#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree[10];

int main() {
    // 샘플 트리: 1(루트) -> 2,3 / 2 -> 4,5 / 3 -> 6
    tree[1]={2,3}; tree[2]={4,5}; tree[3]={6};

    queue<int> q;
    q.push(1);
    cout << "레벨 순회 순서: ";
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        for (int child : tree[curr]) q.push(child);
    }
    cout << endl; // 출력: 1 2 3 4 5 6
    return 0;
}
