#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int arr[1000001];
int num[1000001]={0};
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> stack;
int n;

void stcmp(int x)
{
	while (! stack.empty()&& stack.top().first < num[arr[x]] )
	{
		arr[stack.top().second] = arr[x];
		stack.pop();
	}
	stack.push({ num[arr[x]], x });
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		num[arr[i]]++;
	}
	for (i = 0; i < n; i++)
		stcmp(i);
	while(!stack.empty())
	{
		arr[stack.top().second] = -1;
		stack.pop();
	}
	cout << arr[0];
	for (i = 1; i < n; i++)
		cout << " " << arr[i];
}