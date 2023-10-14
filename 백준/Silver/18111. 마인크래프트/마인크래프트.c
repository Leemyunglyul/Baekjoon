int main()
{
	int n, m, i, j, x, ivt;
	scanf("%d %d %d", &n, &m, &ivt);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * m);
	int min = 257;
	int max = -1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (min > arr[i][j])
				min = arr[i][j];
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	int time = 0;
	int h = 0;
	int inventory, t;
	for (x = min; x <= max; x++)
	{
		inventory = ivt;
		t = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (arr[i][j] > x)
				{
					inventory += (arr[i][j] - x);
					t += 2 * (arr[i][j] - x);
				}
				else if (arr[i][j] < x)
				{
					inventory -= (x - arr[i][j]);
					t += x - arr[i][j];
				}
			}
		}
		if (inventory < 0);
		else if (time == 0 || t <= time)
		{
			time = t;
			h = x;
		}
	}
	printf("%d %d", time, h);
	return 0;
}