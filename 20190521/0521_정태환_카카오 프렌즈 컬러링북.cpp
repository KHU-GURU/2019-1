/*
	from : https://programmers.co.kr/learn/courses/30/lessons/1829
*/
#include<bits/stdc++.h>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool check[101][101];
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	memset(check, false, sizeof(check));
	int number_of_area = 0;
	vector<int> res;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			if (check[i][j] || !picture[i][j])
				continue;

			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			check[i][j] = true;
			int now = picture[i][j];

			int area = 0;
			number_of_area += 1;

			while (!q.empty()) {
				auto front = q.front();
				q.pop();
				area += 1;

				for (int k = 0; k < 4; k++) {
					int nx = front.first + dx[k];
					int ny = front.second + dy[k];
					if (0 <= nx && nx < m && 0 <= ny && ny < n && !check[nx][ny] && now == picture[nx][ny]) {
						q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}

			res.push_back(area);
		}
	}
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = res[0];
	return answer;
}

int main() {
	solution(6, 4, { 
			{1, 1, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 1}
		});
}