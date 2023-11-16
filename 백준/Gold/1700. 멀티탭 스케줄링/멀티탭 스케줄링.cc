#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
vector<int> input;
vector<int> cmp;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k, i, j, num, m, a, pos;
	cin >> n >> k;
	if (n >= k) {
		cout << "0";
		return 0;
	}
	vector<int>::iterator iter;
	for (i = 0, num=0; i < k; i++) {
		cin >> m;
		input.push_back(m);
	}
	while (cmp.size()<n && input.empty()==0) {
		if (cmp.empty() == 1) {
			cmp.push_back( input[0]);
		}
		else if(find(cmp.begin(), cmp.end(), input[0]) == cmp.end()){
			cmp.push_back(input[0]);
		}
		input.erase(input.begin());
	}
	while (input.empty() == 0) {
		if (find(cmp.begin(), cmp.end(), input[0]) != cmp.end());
		else {
			for (i = 0, j=-1, pos=0; i < n; i++) {
				for (a = 1; a < input.size(); a++) {
					if (cmp[i] == input[a] && a > j) {
						j = a;
						pos = i;
						break;
					}
					else if (cmp[i] == input[a]) break;
				}
				if (a == input.size()) {
					pos = i;
					break;
				}
			}
			cmp[pos] = input[0];
			num++;
			/*cout << endl;
			for (i = 0; i < n; i++) {
				cout << cmp[i] << " ";
			}
			cout << endl;*/
		}
		input.erase(input.begin());	
	}
	cout << num;
}