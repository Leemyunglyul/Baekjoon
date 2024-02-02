#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;
long long int put[22] = { 0 };

vector<string> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x;
	long long int n, k, i, j, sum, num;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	for (i = 0, sum=0, num=0; i < n; i++) {
		if (num==0) {
			put[arr[i].size()]++;
			num++;
			continue;
		}
		if (num < k) {
			sum += put[arr[i].size()]++;
			num++;
		}
		else if(num==k) {
			sum += put[arr[i].size()]++;
			put[arr[i - k].size()]--;
		}
	}
	cout << sum;
}