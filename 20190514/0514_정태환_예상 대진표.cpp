/*
	from : https://programmers.co.kr/learn/courses/30/lessons/12985
*/
#include<bits/stdc++.h>
using namespace std;

int solution(int n, int aa, int bb){

	int a = min(aa, bb);
	int b = max(aa, bb);

	deque<int> dq;
	int d = 1;
	for (int i = 2; i <= n; i *= 2) {
		if (i == n) break;
		d++;
	}

	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	
	for (int i = 1; i <= d; i++) {
		deque<int> newdq;
		while (!dq.empty()) {
			int first = dq.front();
			dq.pop_front();
			int second = dq.front();
			dq.pop_front();

			if (first == a && second == b || first == b && second == a)
				return i;
			else if (first == a || second == a)
				newdq.push_back(a);
			else if (first == b || second == b)
				newdq.push_back(b);
			else newdq.push_back(first);
		}
		dq = newdq;
	}
	return 0;
}