#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int m, n, k; // n이 x, m이 y, 원점이 0,0
vector<vector<int>> table;
bool dup[100][100] = { false };
queue<pair<int, int>> q;
int area = 0;
vector<int> sol;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };

void bfs() {
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (table[y][x] == 1 || dup[y][x] == true)
				continue;
			q.push({ y,x });
			dup[y][x] = true;
			area++;
			int check = 1;
			while (!q.empty()) {
				int curY = q.front().first;
				int curX = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = curX + dirX[i];
					int ny = curY + dirY[i];
					if (nx<0 || ny<0 || ny>m - 1 || nx>n - 1)
						continue;
					else if (dup[ny][nx] == true)
						continue;
					else if (table[ny][nx] == 1)
						continue;
					else {
						q.push({ ny,nx });
						dup[ny][nx] = true;
						check++;
					}
				}
			}
			sol.push_back(check);
		}
	}
}
int main() {
	cin >> m >> n >> k;
	table.assign(m, vector<int>(n, 0));

	for (int i = 0; i < k; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		// 왼쪽 하단은 그냥 넣고 오른쪽 상단은 -1씩해서 넣음
		for (int y = sy; y < ey; y++) {
			for (int x = sx; x < ex; x++) {
				table[m - 1 - y][x] = 1;
			}
		}
	}

	bfs();
	cout << area << endl;
	sort(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}



	return 0;
}