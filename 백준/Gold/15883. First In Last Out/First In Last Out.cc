#include<iostream>
#include<math.h>

using namespace std;

int a[5], b[5], sum[6];
int arr[16] = {0};

void print() {
	int i, dec, temp;
	char x;
	for (i = 0; i <= 3; i++) {
		x = a[i] - 10 + 97;
		if (a[i] <= 9) cout << a[i];
		else cout << x;
	}
	cout << " + ";
	for (i = 0; i <= 3; i++) {
		x = b[i] - 10 + 97;
		if (b[i] <= 9) cout << b[i];
		else cout << x;
	}
	cout << " = ";
	for (i = 0; i <= 4; i++) {
		x = sum[i] - 10 + 97;
		if (sum[i] <= 9) cout << sum[i];
		else cout << x;
	}
	cout << "\n";
}

void judge() {
	int i, j, k, l, s, dec, temp;
	for (i = 1; i <= 15; i++) {
		if (arr[i] == 1 || i + a[0] < 15) continue;
		b[0] = i;
		arr[i] = 1;
		b[4] += i * 16 * 16 * 16;
		for (j = 0; j <= 15; j++) {
			if (arr[j] == 1) continue;
			arr[j] = 1;
			b[3] = j;
			b[4] += j;
			s = a[4] + b[4];
			dec = 16 * 16 * 16 * 16;
			for (k = 0; k <= 4; k++) {
				temp = s / dec;
				sum[k] = temp;
				if (k >= 2 && arr[temp] == 1) break;
				else if (k == 0 && sum[0] != a[2]) break;
				else if (k == 1 && sum[1] != a[3]) break;
				arr[temp] = 1;
				s = s - temp * dec;
				dec /= 16;
			}
			if (k == 5) print();
			if(k>=2){
				for (l = 2; l < k; l++) {
					arr[sum[l]] = 0;
				}
			}
			arr[j] = 0;
			b[4] -= j;
		}
		b[4]-= i * 16 * 16 * 16;
		arr[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, n, k, l;
	for (i = 1; i <= 15; i++) {
		a[0] = i;
		b[2] = i;
		arr[i] = 1;
		for (j = 0; j <= 15; j++) {
			if (arr[j] == 1) continue;
			a[1] = j;
			b[1] = j;
			arr[j] = 1;
			for (k = 1; k <= 15; k++) {
				if (arr[k] == 1) continue;
				a[2] = k;
				//sum[0] = k;
				arr[k] = 1;
				for (l = 0; l <= 15; l++) {
					if (arr[l] == 1) continue;
					arr[l] = 1;
					a[3] = l;
					//sum[1] = l;
					a[4] = l + k * 16 + j * 16 * 16 + i * 16 * 16 * 16;
					b[4] = i * 16 + j * 16 * 16;
					//sum[5] = k * 16 * 16 * 16 * 16 + l * 16 * 16 * 16;
					judge();
					arr[l] = 0;
				}
				arr[k] = 0;
			}
			arr[j] = 0;
		}
		arr[i] = 0;
	}
}