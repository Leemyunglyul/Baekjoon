#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
//#include <cmath>
#include <queue>
//#include <stack>
//#include <algorithm>

using namespace std;
int bit[60];
unsigned long long int cmp[60][4];

int main() {
	unsigned long long int n, x, num, a, b, c, d;
	long long int i;
	cin >> n;
	for (i = 59, x = n, num = 576460752303423488; i >= 0; i--, num /= 2) {
		if (x >= num) {
			bit[i] = 1;
			x -= num;
		}
		else bit[i] = 0;
		//cout << bit[i];
	}
	//cout << endl;
	for(i=1, cmp[0][0]=1, cmp[0][1]=1, cmp[0][2]=1, cmp[0][3]=0;i<=59;i++){
		cmp[i][0] = (cmp[i - 1][0] * cmp[i - 1][0] + cmp[i - 1][1] * cmp[i - 1][2]) % 1000000;
		cmp[i][1] = (cmp[i - 1][0] * cmp[i - 1][1] + cmp[i - 1][1] * cmp[i - 1][3]) % 1000000;
		cmp[i][2] = (cmp[i - 1][2] * cmp[i - 1][0] + cmp[i - 1][3] * cmp[i - 1][2]) % 1000000;
		cmp[i][3] = (cmp[i - 1][2] * cmp[i - 1][1] + cmp[i - 1][3] * cmp[i - 1][3]) % 1000000;
		//cout << i << endl << cmp[i][0] << " " << cmp[i][1] << endl << cmp[i][2] << " " << cmp[i][3] << endl << endl;
	}
	unsigned long long int arr[4] = {1, 0, 0, 1};
	for (x=1, i = 0; i <= 59; i++) {
		if (x == 1 && bit[i] == 1) {
			arr[0] = cmp[i][0];
			arr[1] = cmp[i][1];
			arr[2] = cmp[i][2];
			arr[3] = cmp[i][3];
			x = 0;
			//cout << i << endl << arr[0] << " " << arr[1] << endl << arr[2] << " " << arr[3] << endl << endl;
			continue;
		}
		if (x==0&& bit[i] == 1) {
			a= (arr[0] * cmp[i][0] + arr[1] * cmp[i][2]) % 1000000;
			b = (arr[0] * cmp[i][1] + arr[1] * cmp[i][3]) % 1000000;
			c = (arr[2] * cmp[i][0] + arr[3] * cmp[i][2]) % 1000000;
			d= (arr[2] * cmp[i][1] + arr[3] * cmp[i][3]) % 1000000;
			arr[0] = a;
			arr[1] = b;
			arr[2] = c;
			arr[3] = d;
			//cout << i<<endl << arr[0] << " " << arr[1] << endl << arr[2] << " " << arr[3] << endl << endl;
		}	
		
	}
	//cout << arr[0] << " " << arr[1] << endl << arr[2] << " " << arr[3];
	cout << arr[1];
	return 0;
}