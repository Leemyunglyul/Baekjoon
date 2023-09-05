int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	long long * arr = (long long*)malloc(sizeof(long long) * n);
	for (i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	qsort(arr, n, sizeof(long long), compare);
	long long sum = 0;
	for (i = 1; i < n; i++)
		arr[i] += arr[i - 1];
	for (i = 0; i < n; i++)
		sum += arr[i];
	printf("%lld", sum);

}