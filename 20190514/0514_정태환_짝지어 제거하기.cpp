/*
	from : https://programmers.co.kr/learn/courses/30/lessons/12973
*/
#include<bits/stdc++.h>
using namespace std;

int solution(string s){
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (st.empty()) 
			st.push(s[i]);
		else {
			if (st.top() == s[i])
				st.pop();
			else {
				st.push(s[i]);
			}
		}
	}
	return st.empty() ? 1 : 0;
}