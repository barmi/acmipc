//
// Created by skshin on 2025. 9. 13..
//

// https://www.acmicpc.net/problem/2630
// 색종이 만들기
/*
 * 분할 정복
 * 1. 전체 종이를 확인하여 모두 같은 색인지 검사
 * 2. 모두 같은 색이면 해당 색의 개수 증가
 * 3. 모두 같은 색이 아니면 종이를 4등분하여 각 부분에 대해 동일한 작업 수행
 * 4. 재귀적으로 분할 정복을 통해 모든 부분을 검사
 * 5. 최종적으로 흰색과 파란색 종이의 개수 출력
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 128;
int paper[MAX][MAX];
int whiteCount = 0;
int blueCount = 0;

void countPaper(int x, int y, int size) {
	int firstColor = paper[x][y];
	bool allSame = true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (paper[i][j] != firstColor) {
				allSame = false;
				break;
			}
		}
		if (!allSame)
			break;
	}

	if (allSame) {
		if (firstColor == 0)
			whiteCount++;
		else
			blueCount++;
	} else {
		int newSize = size / 2;

		countPaper(x, y, newSize);
		countPaper(x, y + newSize, newSize);
		countPaper(x + newSize, y, newSize);
		countPaper(x + newSize, y + newSize, newSize);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	countPaper(0, 0, N);
	cout << whiteCount << '\n' << blueCount << '\n';

	return 0;
}
