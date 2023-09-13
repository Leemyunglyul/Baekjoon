int a[100][100];
int b[100][100];
int c[100][100];

int main()
{
	int m, n, k, i, j, x, y, z;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			scanf("%d", &b[i][j]);
	x = 0;
	for (i = 0; i < m; i++)
	{
		z = 0;
		for (j = 0; j < k; j++)
		{
			y = 0;
			c[i][j] = 0;
			while (y < n)
			{
				c[i][j] += a[x][y] * b[y][z];
				y++;
			}
			z++;
		}
		x++;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < k; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}