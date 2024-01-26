#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

int arr[100] = { 0 };
string x;

int mt(int dir, int num) {
	int i;
	if (dir == -1) {
		for (i = num-1; i >= 0; i--) {
			if (x[i] == '.') return 100;
			else if (x[i] == '_') continue;
			else if (x[i] == '\\' || x[i] == '|') return 0;
		}
	}
	else {
		for (i = num + 1; i <x.size(); i++) {
			if (x[i] == '.') return 100;
			else if (x[i] == '_') continue;
			else if (x[i] == '/' || x[i] == '|') return 0;
		}
	}
	return 100;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, i;
	double sum;
	cin >> x;
	if (x == "#") return 0;
	while (1) {
		for (i = 0; i < x.size(); i++) {
			if (x[i] == '.') arr[i] = 100;
			else if (x[i] == '_')arr[i] = 0;
			else if (x[i] == '|') {
				arr[i] = (mt(-1, i) + mt(1, i))/2;
			}
			else if (x[i] == '/') {
				arr[i] = mt(-1, i);
			}
			else if (x[i] == '\\') {
				arr[i] = mt(1, i);
			}
		}
		for (i = 0, sum=0; i < x.size(); i++) {
			sum += arr[i];
			//cout << i << " " << arr[i] << endl;
			arr[i] = 0;
		}
		cout << floor(sum / x.size()) << endl;
		cin >> x;
		if (x == "#") return 0;
	}

}