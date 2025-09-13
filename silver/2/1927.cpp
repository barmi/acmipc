//
// Created by skshin on 2025. 9. 13..
//

// https://www.acmicpc.net/problem/1927
// 최소 힙

/*
 * 우선순위 큐
 * 1. 최소 힙을 사용하여 삽입과 삭제 연산을 효율적으로 처리
 * 2. 삽입 연산: O(log n)
 * 3. 삭제 연산: O(log n)
 *
 * priority_queue를 이용해서 최소힙을 구현
 * priority_queue<int, vector<int>, greater<int>> minHeap;
 *      - int: 힙에 저장할 데이터 타입
 *      - vector<int>: 내부적으로 데이터를 저장할 컨테이너
 *      - greater<int>: 최소 힙을 만들기 위한 비교 함수
 *      - 기본적으로 priority_queue는 최대 힙으로 동작하므로, greater<int>를 사용하여 최소 힙으로 변경
 *
 * 4. 입력이 0일 때, 힙이 비어있으면 0 출력, 아니면 최솟값 출력 후 삭제
 * 5. 입력이 자연수 x일 때, 힙에 x 삽입
 * 6. 모든 연산을 처리한 후 결과 출력
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> minHeap;

	int N;
	cin >> N;
	while (N--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (minHeap.empty()) {
				cout << "0\n";
			} else {
				cout << minHeap.top() << '\n';
				minHeap.pop();
			}
		} else {
			minHeap.push(x);
		}
	}

	return 0;
}