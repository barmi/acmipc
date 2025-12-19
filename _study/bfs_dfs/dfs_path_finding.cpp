#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10];
bool visited[10];
bool found = false;

void checkPath(int curr, int target) {
    if (curr == target) {
        found = true;
        return;
    }
    visited[curr] = true;
    for (int next : adj[curr]) {
        if (!visited[next] && !found) checkPath(next, target);
    }
}

int main() {
    adj[1]={2}; adj[2]={3}; adj[3]={4}; // 1->2->3->4 경로
    adj[5]={6}; // 5->6 경로는 끊김

    checkPath(1, 4);
    cout << "1에서 4까지 경로 존재: " << (found ? "YES" : "NO") << endl; // YES
    
    found = false;
    for(int i=0; i<10; i++) visited[i] = false;
    checkPath(1, 6);
    cout << "1에서 6까지 경로 존재: " << (found ? "YES" : "NO") << endl; // NO
    return 0;
}
