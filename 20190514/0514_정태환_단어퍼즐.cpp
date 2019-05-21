/*
	from : https://programmers.co.kr/learn/courses/30/lessons/12983
*/
#include<bits/stdc++.h>
using namespace std;

int d[20001];
map<string, bool> m;
int solution(vector<string> strs, string t){
	for (string str : strs) {
		m[str] = true;
	}

	int tlen = t.length();
	for (int i = 0; i < tlen; i++)
		d[i] = 99999;
	for (int i = 0; i < tlen; i++) {
		for (int len = 1; len <= 5; len++) {
			string temp = t.substr(i, len);
			if (i + len <= tlen && m[temp]) {
				if (i == 0)
					d[i + len - 1] = 1;
				else
					d[i + len - 1] = min(d[i + len - 1], d[i - 1] + 1);
			}
		}
	}
	return d[tlen - 1] == 99999 ? -1 : d[tlen - 1];
}

int main() {
	cout << solution({ "ba","na","n","a" }, "banana");
}