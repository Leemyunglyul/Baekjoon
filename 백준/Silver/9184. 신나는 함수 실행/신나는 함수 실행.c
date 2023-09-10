int arr[21][21][21];

int w(int a, int b, int c)
{
    if (arr[a][b][c] != -500000)
        return arr[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a < b && b < c)
        return (w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
    else
        return (w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
}

int main()
{

    int a, b, c, i, j, k;
    for (i = 0; i <= 20; i++)
        for (j = 0; j <= 20; j++)
            for (k = 0; k <= 20; k++)
                arr[i][j][k] = -500000;
    for (i = 0; i <= 20; i++)
    {
        for (j = 0; j <= 20; j++)
        {
            for (k = 0; k <= 20; k++)
            {
                arr[i][j][k]=w(i, j, k);
            }
        }
    }
    
    scanf("%d %d %d", &a, &b, &c);
    getchar();
    while (a != -1 || b != -1 || c != -1)
    {
        if (a <= 0 || b <= 0 || c <= 0)
            printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
        else if (a > 20 || b > 20 || c > 20)
            printf("w(%d, %d, %d) = %d\n", a, b, c, arr[20][20][20]);
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, arr[a][b][c]);
        
        scanf("%d %d %d", &a, &b, &c);
        getchar();
    }
    
}