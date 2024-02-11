#include<iostream>
#include<math.h>

using namespace std;

int home[1010][3];
int cost[1010][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, k, a1, a2, a3;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	home[0][0] = cost[0][0];
	home[0][1] = cost[0][1];
	home[0][2] = cost[0][2];
	//Red
	for (i = 1; i <= n-1; i++) {
		if (i == n - 1) {
			home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
			home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
			a1 = min(home[i][1], home[i][2]);
			break;
		}
		if (i == 1) {
			home[i][0] = 100000000;
			home[i][1] = home[i - 1][0] +cost[i][1];
			home[i][2] = home[i - 1][0]+cost[i][2];
		}
		else {
			home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
			home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
			home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
		}
		
	}
	//Green
	for (i = 1; i <= n - 1; i++) {
		if (i == n - 1) {
			home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
			home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
			a2 = min(home[i][0], home[i][2]);
			break;
		}
		if (i == 1) {
			home[i][1] = 100000000;
			home[i][0] = home[i - 1][1] + cost[i][0];
			home[i][2] = home[i - 1][1]+cost[i][2];
		}
		else {
			home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
			home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
			home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
		}
	}
	//Blue
	for (i = 1; i <= n - 1; i++) {
		if (i == n - 1) {
			home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
			home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
			a3 = min(home[i][0], home[i][1]);
			break;
		}
		if (i == 1) {
			home[i][2] = 100000000;
			home[i][0] = home[i - 1][2] + cost[i][0];
			home[i][1] =  home[i - 1][2]+ cost[i][1];
		}
		else {
			home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[i][2];
			home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[i][0];
			home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[i][1];
		}
		
	}
	//cout<< a1<<"//"<<a2<<"//"<<a3<<endl;
	cout << min(a1, min(a2, a3));
}