int a[38][5][5];
int b[39];
int c[5][5];
int xyz[5][5];

int divide(long long n)
{
	long long dec2 = 1;
	int i=0;
	long long x = n;
	while (x > 0)
	{
		x /=2;
		i++;
		if (x == 1)
		{
			i++;
			break;
		}
	}
	int j;
	for (j = i - 1; j > 0; j--)
		dec2 *= 2;
	for (j = i - 1; j >= 0; j--)
	{
		if (j == 0)
			b[0] = n;
		else
		{
			b[j] = n / dec2;
			n = n % dec2;
		}
		dec2 /= 2;
		
	}
	return i;
}

void cal(int n, int m)
{
	int i, j, k, x, y, z;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < m; k++)
			{
				x = 0;
				a[i][j][k] = 0;
				while (x < m)
				{
					a[i][j][k] += (a[i - 1][j][x] * a[i - 1][x][k])%1000;
					x++;
				}
				a[i][j][k] %= 1000;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (b[i] != 0)
			break;
	}
	z = i;
	for (j = 0; j < m; j++)
	{
		for (k = 0; k < m; k++)
		{
			c[j][k] = a[z][j][k];
			xyz[j][k] = a[z][j][k];
		}
	}
	for (i = z+1; i < n; i++)
	{
		if (b[i] == 0)
			continue;
		for (y = 0; y < b[i]; y++)
		{
			for (j = 0; j < m; j++)
			{
				for (k = 0; k < m; k++)
				{
					x = 0;
					xyz[j][k] = 0;
					while (x < m)
					{
						xyz[j][k] += (c[j][x] * a[i][x][k])%1000;
						x++;
					}
				}
				xyz[j][k] %= 1000;
			}
			for (j = 0; j < m; j++)
				for (k = 0; k < m; k++)
					c[j][k] = xyz[j][k];
		}
	}
}

int main()
{
	long long n, k, i , j;
	scanf("%lld %lld", &n, &k);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &a[0][i][j]);
		getchar();
	}
	cal(divide(k), n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", c[i][j]%1000);
		printf("\n");
	}
}