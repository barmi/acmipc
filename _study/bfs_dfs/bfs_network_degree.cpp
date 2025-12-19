#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> friends[10];
int dist[10];

int main() {
    // 1-2, 2-3, 3-4, 1-5, 5-4 인맥 구성
    friends[1]={2,5}; friends[2]={1,3}; friends[3]={2,4};
    friends[4]={3,5}; friends[5]={1,4};

    for(int i=0; i<10; i++) dist[i] = -1;

    queue<int> q;
    q.push(1); // '나'로부터 시작
    dist[1] = 0;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int next : friends[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    cout << "1번과 4번의 인맥 거리: " << dist[4] << "단계" << endl;
    return 0;
}
