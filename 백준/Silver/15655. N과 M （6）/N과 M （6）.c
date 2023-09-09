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
int p[9];
int used[9];
int N, M;

int backtracking(int idx, int cut) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", p[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 0 && cut < i) {
			p[idx] = arr[i];
			used[i] = 1;
			backtracking(idx + 1, i);
			used[i] = 0;
		}
	}
}

int main() {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	backtracking(0, -1);
	return 0;
}