#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, m, k, i, x, a,b, c;
	cin >> n>>m>>k;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<long long> varr(n);
	vector<long long> seg_tree(tree_size);
	for (i = 0; i < n; i++) {
		cin >> varr[i];
	}
	init(varr, seg_tree, 1, 0, n - 1);
	for (i = 0; i < m+k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - varr[b - 1];
			varr[b - 1] = c;
			update(seg_tree, 1, 0, n - 1, b - 1, diff);
		}
		else {
			cout<<sum(seg_tree, 1, 0, n - 1, b-1, c-1)<<"\n";
		}
	}
}