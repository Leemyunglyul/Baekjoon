#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, idx;
	cin>>n>>k;
	for (int i=1; i<=n; i++) {
		cin>>arr[i];
	}
	sort(arr+1, arr+n+1);
	if(n==1){
		cout<<arr[1]+k;
		return 0;
	}
	idx = 1;
	while(idx<n){
		int diff = arr[idx+1] - arr[idx];
		if(diff * idx <= k){
			k -= diff * idx;
			arr[idx] += diff;
			idx++;
		}
		else{
			arr[idx] += k / idx;
			k = 0;
			break;
		}
	}
	if(k>0){
		arr[idx] += k / idx;
	}
	cout<<arr[idx];
	return 0;

	
}