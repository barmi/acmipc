#include <iostream>
#include <vector>

using namespace std;

int n = 5, m = 3; // 3개 중 2개 뽑기
bool visited[10];
vector<int> path;

void generate(int depth) {
    if (depth == m) {
        for (int x : path) cout << x << " ";

//        cout << " (";
//        for (int x : visited) cout << x << ", ";

        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            generate(depth + 1);
            path.pop_back(); // 백트래킹: 선택 취소
            visited[i] = false;
        }
    }
}

int main() {
    cout << "3개 중 2개를 뽑는 순열:" << endl;
    generate(0);
    return 0;
}
