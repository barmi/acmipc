//
// Created by skshin on 2025. 9. 13..
//
// https://www.acmicpc.net/problem/1012

/*
 * DFS, BFS
 * 1. 배추밭을 2차원 배열로 표현
 * 2. 배추가 심어진 위치를 1로 표시
 * 3. 방문한 위치를 0으로 변경하면서 상하좌우로 인접한 배추들을 모두 방문 처리
 * 4. 모든 위치를 순회하면서 방문하지 않은 배추가 있으면 새로운 지렁이 필요, 지렁이 수 증가
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 50;
int field[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int M, N;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = 1;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = curX + dx[i];
			int newY = curY + dy[i];

			if (newX >= 0 && newX < M && newY >= 0 && newY < N) {
				if (field[newX][newY] == 1 && !visited[newX][newY]) {
					visited[newX][newY] = 1;
					q.push({newX, newY});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		memset(field, 0, sizeof(field));
		memset(visited, 0, sizeof(visited));
		int K;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[x][y] = 1;
		}

		int wormCount = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					wormCount++;
				}
			}
		}
		cout << wormCount << '\n';
	}

	return 0;
}
