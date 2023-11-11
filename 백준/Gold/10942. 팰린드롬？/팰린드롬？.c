int arr[2004] = {0};
int mem[2004][2004] = {0};

int main() {
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, i, j, k, m;
	scanf("%d",&n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		mem[i][i] = 1;
	}
	for (i = 1; i <= n; i++) {
		if (arr[i] == arr[i + 1]) mem[i][i + 1] = 1;
		if (arr[i] == arr[i + 2]) mem[i][i + 2] = 1;
	}
	for (i = 3; i < n; i++) {
		for (j = 1; j <=n-i; j++) {
			if (mem[j + 1][j + i - 1] == 1 && arr[j]==arr[j+i]) mem[j][j + i] = 1;
		}
	}
	scanf("%d",&n);
	while (n--) {
		scanf("%d%d", &i, &j);
		printf("%d\n", mem[i][j]);
	}	
}