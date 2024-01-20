#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<queue>
//#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
//#include<functional>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string pin, check;
	cin >> pin >> check;
	int sum, i, pre, j;
	for (sum = 0, i = 0; i < check.size(); i++) {
		if (check[i]>90) sum += check[i] - 96;
		else sum+=check[i] - 64;
	}
	if (sum != pin.size()) cout << "non sequitur";
	else {
		for (i = 0, pre=0, sum=0; i < check.size(); i++) {
			if (check[i]>90) {
				for (j = pre; j < pre + check[i] - 96; j++) {
					sum+= pin[j]-48;
				}
				pre += check[i] - 96;
			}
			else {
				pre += check[i] - 64;
			}
		}
		cout << sum;
	}

}