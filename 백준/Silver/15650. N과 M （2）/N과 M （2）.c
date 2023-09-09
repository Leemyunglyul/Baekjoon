int rearr(int depth[], int n, int m, int* dep, int * judge)
{
	if (*judge == -1)
		return 0;
	int i, temp;
	int arr[9] = {0};
	temp = *dep;
	int max = -1;
	for (i = 1; i <= temp; i++)
		if (max < depth[i])
			max = depth[i];
	for (i = 0; i <= max; i++)
		arr[i] = 1;
	if (n - max < m - temp + 1)
	{
		*dep = *dep - 1;
		if (temp == 1)
		{
			*judge = -1;
			return 0;
		}
		rearr(depth, n, m, dep, judge);
	}
	else
	{
		int s = temp;
		for (i = max+1; i <= n; i++)
			depth[s++] = i;
	}
	*dep = *dep + 1;
	if (*dep > m)
		*dep = m;
	return 0;
}

int main()
{
	int n, m, i;
	scanf("%d %d", &n, &m);
	int* depth = (int*)malloc(sizeof(int) * (n+1));
	for (i = 1; i <= n; i++)
		depth[i] = i;
	int dep = m;
	int j = 0;
	while (j==0)
	{
		printf("%d", depth[1]);
		for (i = 2; i <= m; i++)
			printf(" %d", depth[i]);
		printf("\n");
		rearr(depth, n, m, &dep, &j);
	}
	return 0;
}