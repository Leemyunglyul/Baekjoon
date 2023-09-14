long long int a[66][2][2];
int b[66] = {0};
long long int c[2][2];
long long int xyz[2][2];

int divide(unsigned long long int n)
{
	unsigned long long int dec2 = 1;
	int i = 0;
	unsigned long long int x = n;
	while (x > 0)
	{
		x /= 2;
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

void cal(int n)
{
	int i, j, k, x, y, z;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				x = 0;
				a[i][j][k] = 0;
				while (x < 2)
				{
					a[i][j][k] += (a[i - 1][j][x] * a[i - 1][x][k]) % 1000000007;
					x++;
				}
				a[i][j][k] %= 1000000007;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (b[i] != 0)
			break;
	}
	z = i;
	for (j = 0; j < 2; j++)
	{
		for (k = 0; k < 2; k++)
		{
			c[j][k] = a[z][j][k];
			xyz[j][k] = a[z][j][k];
		}
	}
	for (i = z + 1; i < n; i++)
	{
		if (b[i] == 0)
			continue;
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				x = 0;
				xyz[j][k] = 0;
				while (x < 2)
				{
					xyz[j][k] += (c[j][x] * a[i][x][k]) % 1000000007;
					x++;
				}
				xyz[j][k] %= 1000000007;
			}
		}
		for (j = 0; j < 2; j++)
			for (k = 0; k < 2; k++)
				c[j][k] = xyz[j][k];
	}
}

int main()
{
	unsigned long long int n;
	scanf("%lld", &n);
	if (n == 1)
		printf("1");
	else {
		a[0][0][0] = 1;
		a[0][0][1] = 1;
		a[0][1][0] = 1;
		a[0][1][1] = 0;
		cal(divide(n));
		printf("%d", c[0][1] % 1000000007);
	}
}