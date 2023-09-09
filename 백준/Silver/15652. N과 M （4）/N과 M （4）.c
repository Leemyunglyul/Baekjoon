int arr[9];
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	backtracking(0, 0);
	return 0;
}

int backtracking(int idx, int cut) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (cut <= i)
		{
			arr[idx] = i;
			backtracking(idx + 1, i);
		}
	}
}