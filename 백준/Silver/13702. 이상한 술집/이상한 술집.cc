#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int arr[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	for (int i=0; i<n; i++) {
		cin>>arr[i];
	}
	sort(arr, arr+n, greater<int>());
	if(n==1){
		cout<<arr[0]<<'\n';
		return 0;
	}

	long long l=0; 
	long long r=arr[0];
	long long anw =0;

	while(l<=r){
		long long mid = (l+r)/2;
		long long sum=0;
		if(mid==0 || k == 0){
			break;
		}
		for(int i=0; i<n; i++){
			if(arr[i]>mid){
				sum+=arr[i]/mid;
			}
			else break;
		}
		if(sum>=k){
			anw = max(anw,mid);
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout<<anw;
}