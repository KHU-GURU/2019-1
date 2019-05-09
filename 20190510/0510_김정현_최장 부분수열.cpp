#include <iostream>
#include <algorithm>
using namespace std;

int segtree[(int)5e5 * 4] = {};

void segtree_init() {
	// no need :p
}

void segtree_update(int i, int l, int r, int p, int v) {
	if (l > r)
		return;
	if (p < l || r < p)
		return;
	if (l == r) {
		segtree[i] = v;
		return;
	}
	
	int mid = (l + r) / 2;
	
	segtree_update(i * 2, l, mid, p, v);
	segtree_update(i * 2 + 1, mid + 1, r, p, v);
	segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
}

int segtree_max(int i, int l, int r, int s, int e) {
	if (l <= r && s <= e) {
		if (r < s || e < l)
			return 0;
		if (s <= l && r <= e)
			return segtree[i];
		int mid = (l + r) / 2;

		int val = max(segtree_max(i * 2, l, mid, s, e), 
			segtree_max(i * 2 + 1, mid + 1, r, s, e));
		return val;
	}
	else
		return 0;
}

int main() {
	int n, k, d; scanf("%i%i%i", &n, &k, &d);
	static int l[(int)5e5];
	for (int i = 0; i < n; i++)
		scanf("%i", &l[i]);

	static int modList[(int)5e5] = {};
	int ans = 1;

	for (int i = 0; i < n; i++) {
		int max1 = modList[l[i] % k];
		int max2 = segtree_max(1, 0, (int)5e5-1, l[i] - d, l[i] + d);
		int val = max(max1, max2) + 1;

		modList[l[i] % k] = val;
		segtree_update(1, 0, (int)5e5-1, l[i], val);

		ans = max(ans, val);
	}
	printf("%i", ans);
}