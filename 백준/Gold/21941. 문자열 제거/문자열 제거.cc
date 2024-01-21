#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>
//#include<functional>

using namespace std;

vector<pair<string, int>> sub;
int arr[200][2000] = {0};
int sum[2000] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string ms, subw;
	int n, i, score, j, k;
	cin >> ms >> n;
	for (i = 0;i<n;i++) {
		cin >> subw >> score;
		if (subw.size() >= score || subw.size()>ms.size()) continue;
		sub.push_back({subw, score });
	}
	for (i = 0; i < sub.size(); i++) {//sub 문자열 존재 판단
		for (j = 0; j <= ms.size() - sub[i].first.size(); j++) {
			for (k = 0; k < sub[i].first.size(); k++) {
				if (ms[k+j] != sub[i].first[k])break;
			}
			if (k == sub[i].first.size()) arr[i][j+k - 1] = 1;
		}
	}
	for (i = 0; i < ms.size(); i++) {
		sum[i] = i + 1;
		for (j = 0; j < sub.size(); j++) {
			if (sub[j].first.size() < i + 1 && arr[j][i] == 1) {
				sum[i] = max(sum[i-sub[j].first.size()]+sub[j].second, sum[i]);
			}
			else if (sub[j].first.size() == i + 1 && arr[j][i] == 1) {
				sum[i] = max(sub[j].second, sum[i]);
			}
		}
		if(i>0) sum[i] = max(sum[i - 1] + 1, sum[i]);
	}
	/*for (i = 0; i < ms.size(); i++) {
		cout << i << "점수: " << sum[i] << endl;
	}*/
	cout << sum[ms.size() - 1];
}