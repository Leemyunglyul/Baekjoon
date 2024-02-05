#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int n, big;
int b[22][22];
vector<int> temp;
int x = 0;

void game(int num, int arr[][22]) {
	int i, j, k, r;
	/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}cout << endl;*/

	if (num == 5) return;

	for (i = 0; i < 4; i++) {
		//cout<<endl << num<<"번째 " << i << endl;
		if (i == 0) {//위로
			int g[22][22] = { 0 };
			for (k = 1; k <= n; k++) {
				for (j = 1; j <= n; j++) {
					if (arr[j][k] > 0 && (temp.empty()|| temp.back() != arr[j][k])) {
						temp.push_back(arr[j][k]);
					}
					else if (arr[j][k] > 0 && temp.back() == arr[j][k]) {
						temp.pop_back();
						temp.push_back(2* arr[j][k]);
						temp.push_back(0);
					}
				}
				for (j = 0, r=1; j <temp.size(); j++) {
					if (temp[j] == 0) continue;
					g[r++][k] = temp[j];
					big = max(big, temp[j]);
				}
				temp.clear();
			}
			game(num + 1, g);
		}
		else if (i == 1) {//좌로
			int g[22][22] = { 0 };
			for (j = 1; j <= n; j++) {
				for (k = 1; k <= n; k++) {
					if (arr[j][k] > 0 && (temp.empty() || temp.back() != arr[j][k])) {
						temp.push_back(arr[j][k]);
					}
					else if (arr[j][k] > 0 && temp.back() == arr[j][k]) {
						temp.pop_back();
						temp.push_back(2* arr[j][k]);
						temp.push_back(0);
					}
				}
				for (k = 0, r = 1; k < temp.size(); k++) {
					if (temp[k] == 0) continue;
					g[j][r++] = temp[k];
					big = max(big, temp[k]);
				}
				temp.clear();
			}
			game(num + 1, g);
		}
		else if (i == 2) {//아래로
			int g[22][22] = { 0 };
			for (k = 1; k <=n; k++) {
				for (j = n; j >=1; j--) {
					if (arr[j][k] > 0 && (temp.empty() || temp.back() != arr[j][k])) {
						temp.push_back(arr[j][k]);
					}
					else if (arr[j][k] > 0 && temp.back() == arr[j][k]) {
						temp.pop_back();
						temp.push_back(2 * arr[j][k]);
						temp.push_back(0);
					}
				}
				for (j = 0, r = n; j < temp.size(); j++) {
					if (temp[j] == 0) continue;
					g[r--][k] = temp[j];
					big = max(big, temp[j]);
				}
				temp.clear();
			}
			game(num + 1, g);
		}
		else if (i == 3) {//우로
			int g[22][22] = { 0 };
			for (j = 1; j <= n; j++) {
				for (k = n; k >=1; k--) {
					if (arr[j][k] > 0 && (temp.empty() || temp.back() != arr[j][k])) {
						temp.push_back(arr[j][k]);
					}
					else if (arr[j][k] > 0 && temp.back() == arr[j][k]) {
						temp.pop_back();
						temp.push_back(2* arr[j][k]);
						temp.push_back(0);
					}
				}
				for (k = 0, r = n; k < temp.size(); k++) {
					if (temp[k] == 0) continue;
					g[j][r--] = temp[k];
					big = max(big, temp[k]);
				}
				temp.clear();
			}
			game(num + 1, g);
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int i, j;
	for (i = 1, big=0; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> b[i][j];
			big = max(big, b[i][j]);
		}
	}
	game(0, b);
	cout << big;
}