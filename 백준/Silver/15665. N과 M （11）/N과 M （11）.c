int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int arr[9];
int a[9];
int p[9];
int N, M;

int backtracking(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", p[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
			p[idx] = arr[i];
			backtracking(idx + 1);
	}
}

int main() {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	qsort(a, N, sizeof(int), compare);
	int s = 0;
	for (i = 0; i < N; i++)
	{
		if (a[i - 1] == a[i] && i > 0)
			continue;
		arr[s++] = a[i];
	}
	N = s;
	backtracking(0);
	return 0;
}