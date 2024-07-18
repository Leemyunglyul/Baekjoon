#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    else {
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2)
            ^ init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        if((end-start+1)%2==1) tree[node] ^= lazy[node];
        if (start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        if ((end - start + 1) % 2 == 1) tree[node] ^= diff;
        if (start != end) {
            lazy[node * 2] ^= diff;
            lazy[node * 2 + 1] ^= diff;
        }
        return;
    }
    update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
    update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

long long query(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return query(tree, lazy, node * 2, start, (start + end) / 2, left, right)
        ^ query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);
    vector<long long> lazy(tree_size);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n - 1);
    cin >> m;
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int left, right;
            long long diff;
            cin >> left >> right >> diff;
            update_range(tree, lazy, 1, 0, n - 1, left, right, diff);
        }
        else if (what == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(tree, lazy, 1, 0, n - 1, left, right) << '\n';
        }
    }
    return 0;
}