int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] = arr[i] % m;
    }
    long long* sum = (long long*)malloc(sizeof(long long) * n);
    sum[0] = arr[0];
    for (i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
        sum[i] = sum[i] % m;
    }
    long long* ar = (long long*)malloc(sizeof(long long) * m);
    for (i = 0; i < m; i++)
        ar[i] = 0;
    for (i = 0; i < n; i++)
        ar[sum[i]]++;
    long long num = 0;
    for (i = 0; i < m; i++)
    {
        if (ar[i] <= 1)
            continue;
        else
            num += (ar[i]-1) * ar[i]/2;
        if (i == 0)
            num += ar[i];
    }
    printf("%lld", num);
}