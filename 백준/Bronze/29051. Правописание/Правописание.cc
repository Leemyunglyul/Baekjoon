#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>

using namespace std;
int arr[30];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	arr[0] = 2;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;//F
	arr[6] = 1;
	arr[7] = 3;
	arr[8] = 3;
	arr[9] = 2;
	arr[10] = 3;
	arr[11] = 1;
	arr[12] = 1;
	arr[13] = 1;
	arr[14] = 1;
	arr[15] = 1;
	arr[16] = 1;
	arr[17] = 2;
	arr[18] = 1;
	arr[19] = 2;
	arr[20] = 1;
	arr[21] = 1;
	arr[22] = 1;
	arr[23] = 2;
	arr[24] = 2;
	arr[25] = 1;
	string x;
	cin >> x;
	int sum, i;
	for (i = 0, sum = 0; i < x.size(); i++) {
		sum += arr[x[i] - 65];
	}
	cout << sum;
}