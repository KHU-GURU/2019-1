/*
	from : https://programmers.co.kr/learn/courses/30/lessons/42899
*/
#include<bits/stdc++.h>
using namespace std;

int d[105][100001];
int solution(int K, vector<vector<int>> travel) {
	for (int k = 0; k <= K; k++) {
		int wt = travel[0][0], wc = travel[0][1];
		int bt = travel[0][2], bc = travel[0][3];
		d[0][k] = max(k >= wt ? wc : 0, k >= bt ? bc : 0);
	}
	for (int i = 1; i < travel.size(); i++) {
		int wt = travel[i][0], wc = travel[i][1];
		int bt = travel[i][2], bc = travel[i][3];
		for (int k = 0; k <= K; k++) {
			if (k - wt >= 0 && d[i - 1][k - wt] != 0) {
				d[i][k] = max(d[i][k], d[i - 1][k - wt] + wc);
			}
			if (k - bt >= 0 && d[i - 1][k - bt] != 0) {
				d[i][k] = max(d[i][k], d[i - 1][k - bt] + bc);
			}
		}
	}
	int n = travel.size() - 1;
	return d[n][K];
}

int main() {
	cout << solution(1650, {
		{500, 200, 200, 100},
		{800, 370, 300, 120},
		{700, 250, 300, 90}
	});
}