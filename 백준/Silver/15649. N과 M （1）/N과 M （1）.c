void rearr(int depth[], int n, int m, int * dep)
{
	int i, temp;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		arr[i] = 0;
	temp = *dep;
	for (i = 0; i < temp; i++)
		arr[depth[i]] = 1;
	for (i =0; i < n; i++)
	{
		if (arr[i] == 0 && depth[temp] < i)
		{
			depth[temp] = i;
			break;
		}
	}
	if (i >= n)
	{
		*dep = *dep - 1;
		rearr(depth, n, m, dep);
	}
	else
	{
		arr[depth[temp]] = 1;
		int s = temp + 1;
		for (i = 0; i < n; i++)
		{
			if (arr[i] == 0)
				depth[s++] = i;
		}
	}
	*dep = *dep + 1;
	if (*dep >= m)
		*dep = m - 1;
	return 0;
}

int main()
{
	long long x=1;
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = n; i > n - m; i--)
		x = x*i;
	int* depth = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		depth[i] = i;
	int dep = m-1;
	while (x>0)
	{
		printf("%d", depth[0]+1);
		for (i = 1; i < m; i++)
			printf(" %d", depth[i]+1);
		printf("\n");
		rearr(depth, n, m, &dep);
		x--;
	}
	return 0;
}