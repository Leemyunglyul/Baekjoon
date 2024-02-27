#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;
int arr[510][510], row, col;

int t1(int r, int c) {
	int s1=0;
	int s2 = 0;
	if (c + 3 <= col) {
		s1 = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r][c + 3];
	}
	if (r + 3 <= row) {
		s2 = arr[r][c] + arr[r+1][c] + arr[r+2][c] + arr[r+3][c];
	}
	return max(s1, s2);
}

int t2(int r, int c) {
	int s = 0;
	if (r + 1 <= row && c + 1 <= col) {
		s = arr[r][c] + arr[r][c + 1] + arr[r + 1][c] + arr[r + 1][c + 1];
	}
	return s;
}

int t3(int r, int c) {
	int s1 = 0; int s2 = 0;int s3 = 0;int s4 = 0;
	int s5 = 0; int s6 = 0; int s7 = 0; int s8 = 0;
	if (r - 2 >= 1 && c + 1 <= col) {
		s1 = arr[r][c] + arr[r - 1][c] + arr[r - 2][c] + arr[r][c + 1];
	}
	if (r - 1 >= 1 && c - 2 >= 1) {
		s2 = arr[r][c] + arr[r - 1][c] + arr[r ][c-2] + arr[r][c - 1];
	}
	if (r +2 <=row && c - 1 >= 1) {
		s3 = arr[r][c] + arr[r + 1][c] + arr[r+2][c] + arr[r][c-1];
	}
	if (r + 1 <= row && c + 2 <=col) {
		s4 = arr[r][c] + arr[r + 1][c] + arr[r][c+1] + arr[r][c +2];
	}
	if (r - 2 >= 1 && c - 1 >= 1) {
		s5 = arr[r][c] + arr[r][c - 1] + arr[r - 1][c] + arr[r - 2][c];
	}
	if (r - 1 >= 1 && c + 2 <= col) {
		s6 = arr[r][c] + arr[r - 1][c] + arr[r][c + 1] + arr[r][c + 2];
	}
	if (r + 2 <= row && c + 1 <= col) {
		s7 = arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r][c + 1];
	}
	if (r + 1 <= row && c - 2 >= 1) {
		s8 = arr[r][c] + arr[r][c - 1] + arr[r][c - 2] + arr[r + 1][c];
	}
	return max(max(max(s1,s2), max(s3, s4)), max(max(s5, s6), max(s7, s8)));
}

int t4(int r, int c) {
	int s1 = 0; int s2 = 0; int s3 = 0; int s4 = 0;
	if (r - 1 >= 1 && r + 1 <= row && c + 1 <= col) {
		s1 = arr[r][c] + arr[r - 1][c] + arr[r][c + 1] + arr[r + 1][c + 1];
	}
	if (c - 1 >= 1 && r - 1 >=1 && c + 1 <= col) {
		s2 = arr[r][c] + arr[r][c-1] + arr[r-1][c] + arr[r - 1][c + 1];
	}
	if (c + 1 <=col && r - 1 >= 1 && r + 1 <= row) {
		s3 = arr[r][c] + arr[r][c+1] + arr[r - 1][c+1] + arr[r +1][c];
	}
	if (c - 1 >=1 && r + 1 <=row && c + 1 <=col) {
		s4 = arr[r][c] + arr[r][c - 1] + arr[r +1][c] + arr[r + 1][c+1];
	}
	return max(max(s1, s2), max(s3, s4));
}

int t5(int r, int c) {
	int s1 = 0; int s2 = 0; int s3 = 0; int s4 = 0;
	if (r - 1 >= 1) s1 = arr[r - 1][c];
	if (c - 1 >= 1) s2 = arr[r][c - 1];
	if (r + 1 <= row) s3 = arr[r + 1][c];
	if (c + 1 <= col) s4 = arr[r][c + 1];
	int sum = s1 + s2 + s3 + s4;
	return arr[r][c] + sum - min(min(s1, s2), min(s3, s4));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	int i, j, big;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 1, big=0; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			big = max(max(t1(i, j), t2(i, j)), max(big, t3(i, j)));
			big = max(big, max(t4(i, j), t5(i, j)));
		}
	}
	cout << big;
}