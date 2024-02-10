#include<iostream>
#include<math.h>


using namespace std;

long long int arr[88];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	long long int n, i;
	cin >> n;
	for (i = 2, arr[0]=0, arr[1]=1; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << 2 * (arr[n] + arr[n]+arr[n-1]);
}