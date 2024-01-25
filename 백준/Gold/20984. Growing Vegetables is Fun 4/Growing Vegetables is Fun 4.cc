#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll arr[200001];
ll a[200001];
ll b[200001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n; ++i)a[i] = max(arr[i - 1] - arr[i] + 1, 0LL) + a[i - 1];
	for (int i = n - 2; i >= 0; --i)b[i] = max(arr[i + 1] - arr[i] + 1, 0LL) + b[i + 1];
	ll ans = LLONG_MAX;
	for (int i = 0; i < n; i++) ans = min(ans, max(a[i], b[i]));
	cout << ans;
}