int arr[100000];
int a[317];

int main()
{
	int i, n, j;
	scanf("%d", &n);
	for (i = 0; i < 317; i++)
		a[i] = (i + 1) * (i + 1);
	for (i = 0; i < 317; i++)
		arr[a[i]-1] = 1;
	for (i = 0; i < 100000; i++)
	{
		if (arr[i] == 1)
		{
			for (j = 0; j < 317; j++)
			{
				if (i + a[j] > 100000)
					break;
				if (arr[i + a[j]] == 1)
					continue;
				arr[i+ a[j]] = 2;
			}
		}
	}
	for (i = 0; i < 100000; i++)
	{
		if (arr[i] == 2)
		{
			for (j = 0; j < 317; j++)
			{
				if (i + a[j] > 100000)
					break;
				if (arr[i + a[j]] == 1 || arr[i + a[j]] == 2)
					continue;
				arr[i + a[j]] = 3;
			}
		}
	}
	if (arr[n - 1] == 0)
		printf("4");
	else
		printf("%d", arr[n - 1]);
}