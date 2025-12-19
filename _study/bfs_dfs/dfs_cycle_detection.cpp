#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10];
bool visited[10];
bool inProgress[10];
bool hasCycle = false;

void findCycle(int curr) {
    visited[curr] = true;
    inProgress[curr] = true; // 현재 탐색 경로에 추가

    for (int next : adj[curr]) {
        if (inProgress[next]) { // 이미 탐색 중인 경로의 노드를 다시 만나면 사이클!
            hasCycle = true;
        } else if (!visited[next]) {
            findCycle(next);
        }
    }
    inProgress[curr] = false; // 탐색을 마치고 나올 때 경로에서 제외
}

int main() {
    // 샘플: 1->2->3->1 (사이클)
    adj[1]={2}; adj[2]={3}; adj[3]={1};
    
    findCycle(1);
    cout << "사이클 존재 여부: " << (hasCycle ? "YES" : "NO") << endl;
    return 0;
}
