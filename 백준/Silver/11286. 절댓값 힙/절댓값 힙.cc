#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
//#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if ((double)a / b > 1 || (double)a / b < -1)
			return 1;
		else if (a / b == -1 || a / b == 1)
			return a > b;
		else
			return 0;
	}
};

int main()
{
	priority_queue<int, vector<int>, cmp> pq;

	int n, i, x;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0){
			if (pq.empty() == 1)
				cout << "0" << endl;
			else{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}