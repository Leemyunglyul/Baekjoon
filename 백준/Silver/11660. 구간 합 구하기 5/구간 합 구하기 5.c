int arr[1030][1030];

int main()
{
    int n, m, i, x1, y1, x2, y2, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j++)
            arr[i][j] = arr[i][j-1]+arr[i][j];
    }
    long long x;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        getchar();
        x = 0;
        if (y1 == 1)
        {
            for (j = x1-1; j <= x2-1; j++)
                x += arr[j][y2-1];
        }
        else
        {
            for (j = x1-1; j <= x2-1; j++)
                x += arr[j][y2-1]-arr[j][y1-2];
        }
        printf("%lld\n", x);
    }

}