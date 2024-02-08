#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int n, sum, i;
	cin >> n;
	string x;
	cin >> x;
	int arr[3] = {0};
	for (i = 0; i < x.size(); i++) {
		if (x[i] == 'B') arr[0]++;
		else if (x[i] == 'S') arr[1]++;
		else arr[2]++;
	}
	sum = max(arr[0], max(arr[1], arr[2]));
	if (arr[0] == arr[1] && arr[1] == arr[2]) cout << "SCU";
	else if (sum == arr[0] && arr[0] == arr[1]) cout << "BS";
	else if (sum == arr[0] && arr[0] == arr[2]) cout << "BA";
	else if (sum == arr[1] && arr[1] == arr[2]) cout << "SA";
	else if (sum == arr[0]) cout << "B";
	else if (sum == arr[1]) cout << "S";
	else if (sum == arr[2]) cout << "A";
}