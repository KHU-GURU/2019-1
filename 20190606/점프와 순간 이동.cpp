/*
	������ ���� �̵� : https://programmers.co.kr/learn/courses/30/lessons/12980
*/

#include<bits/stdc++.h>
using namespace std;

int solution(int n){
	int dis = 0;
	while (n) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n--;
			dis++;
		}
	}
	return dis;
}

int main() {
	cout << solution(5000);
}