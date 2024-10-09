#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int n, m;
int dist[1001] = { 0 };
vector<pair<pi, int>> v;
int solve()
{
	dist[0] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int from = v[j].X.X;
			int to = v[j].X.Y;
			int cost = v[j].Y;
			if (dist[from] == INF)
				continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int j = 0; j < v.size(); j++)
	{
		int from = v[j].X.X;
		int to = v[j].X.Y;
		int cost = v[j].Y;
		if (dist[from] == INF)
			continue;
		if (dist[to] > dist[from] + cost)
			return 0;
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		v.push_back({ {0,i},0 });
	}

	for (int i = 0; i < m; i++)
	{
		int a, x, y, z;
		cin >> x >> a >> y >> z;
		if (a == 1)
		{
			v.push_back({ {x,y},-z });
			if (z == 0)
				v.push_back({ {x,y},z });
		}
		else if (a == 0)
		{
			v.push_back({ {y,x},z });
			if (z == 0)
				v.push_back({ {y,x},-z });
		}
	}

	if (solve())
	{
		int maxx = -INF, minn = INF;
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] > maxx)
				maxx = dist[i];
			if (dist[i] < minn)
				minn = dist[i];
		}
		num = -minn + 1;
		if (maxx + num > 1000000)
		{
			cout << -1 << '\n';
			return 0;
		}
		for (int i = 1; i <= n; i++)
			cout << dist[i] + num << '\n';
	}
	else
		cout << -1 << '\n';
}