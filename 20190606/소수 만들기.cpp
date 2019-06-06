/*
	소수 만들기 : https://programmers.co.kr/learn/courses/30/lessons/12977
*/

#include<bits/stdc++.h>
using namespace std;

bool isnotprime[100001];
int go(vector<int> nums, int pos, int cnt, int sum) {
	if (cnt == 3) {
		if (!isnotprime[sum])
			return 1;
		else return 0;
	}
	int ans = 0;
	for (int i = pos + 1; i < nums.size(); i++) {
		ans += go(nums, i, cnt + 1, sum + nums[i]);
	}
	return ans;
}

int solution(vector<int> nums) {
	isnotprime[1] = true;
	for (int i = 2; i <= 100000; i++) {
		if (!isnotprime[i]) {
			for (int j = i + i; j <= 100000; j += i) {
				isnotprime[j] = true;
			}
		}
	}
	return go(nums, -1, 0, 0);
}

int main() {
	vector<int> v = {1,2,3,4 };
	solution(v);
}