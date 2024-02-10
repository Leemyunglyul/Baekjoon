#include<iostream>
#include<math.h>


using namespace std;

long long int arr[46][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, i;
	cin >> n;
	for (i = 1, arr[0][0]=1, arr[0][1]=0; i <= n; i++) {
		arr[i][0] = arr[i-1][1];
		arr[i][1] = arr[i - 1][0] + arr[i - 1][1];
	}
	cout << arr[n][0] << " " << arr[n][1];
}