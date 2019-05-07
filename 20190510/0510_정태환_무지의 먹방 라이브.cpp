#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> food_times, long long k) {
    bool flag = false;
    long long left = 1, right = LONG_MAX;
    long long mid, sum = 0;
    for (int i = 0; i < food_times.size(); i++) {
        sum += food_times[i];
    }
    if (sum <= k) return -1;
    while (left < right) {
        long long cnt = 0;
        mid = left + (right - left) / 2;
        for (int i = 0; i < food_times.size(); i++) {
            if (food_times[i] >= mid)
                cnt += mid;
            else cnt += food_times[i];
        }
        if (cnt > k)
            right = mid;
        else if(cnt < k)
            left = mid + 1;
        else {
            left = mid + 1;
            flag = true;
        }
    }
    if(flag)
        for (int i = 0; i < food_times.size(); i++)
            if (food_times[i] >= right) {
                return i + 1;
            }

    sum = 0;
    for (int i = 0; i < food_times.size(); i++) {
        if (food_times[i] >= (right - 1))
            sum += (right - 1);
        else sum += food_times[i];
    }   
    long long leave = k - sum;
    for (int i = 0; i < food_times.size(); i++) {
        if (food_times[i] >= right) {
            leave--;
            if (leave == -1)
                return i+1;
        }
    }
    return -1;
}
