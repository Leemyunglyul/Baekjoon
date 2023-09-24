#include <iostream>
//#include <string>
//#include <vector>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
long long int arr[100001];
stack <pair<int,int>>s;
long long int w = 0;

int main()
{
	int n, i, pass;
	long long temp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		pass = 0;
		temp = i;
		while (!s.empty() && arr[i] < arr[s.top().first])
		{
			temp=s.top().second;
			w = max(w, (i-temp)* arr[s.top().first]);
			s.pop();
		}
		if (!s.empty() && arr[i] == arr[s.top().first])
			continue;
		s.push({i, temp});
	}
	while (!s.empty())
	{
		w=max(w, (long long)arr[s.top().first] * (n - s.top().second));
		s.pop();
	}
	cout << w;
	return 0;
}