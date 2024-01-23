
int arr[100010] = {0};
int sum[100010] = { 0 };
long long int sums[100010][20] = { 0 };
int con[100010];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, x, j, n;
	for (i = 1; i <= 100000; i++) con[i] = i;
	for (i = 2; i <= 100000; i++) {
		if (arr[i] == 0) {
			sum[i] = 1;
			x = i*2;
			while (x <= 100000) {
				if (arr[x] == 1);
				else if (arr[x] == 0) {
					arr[x] = 1;
					con[x] = con[x] / i;
					sum[x]++;
				}
				x += i;
			}
		}
	}
	for (i = 2; i <= 100000; i++) {
		if (arr[i] == 1 && con[i] > 1) {
			sum[i] += sum[con[i]];
		}
	}
	for (i = 3, sums[2][1] = 1; i <= 100000; i++) {
		sums[i][sum[i]]++;
		for (j =1; j <= 16; j++) {
			sums[i][j] += sums[i - 1][j];

		}
	}	
	int l, r, k, s;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d", &l, &r, &k);
		printf("%ld\n", sums[r][k] - sums[l - 1][k]);
	}
}