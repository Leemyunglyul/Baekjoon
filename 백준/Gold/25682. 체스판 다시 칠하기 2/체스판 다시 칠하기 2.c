int w[2000][2000];
int b[2000][2000];

int sum(int Row, int Column, int n, int bw)
{
    int i, j;
    int s = 0;
    if (bw == 0)
    {
        if (Row >= 1 && Column >= 1)
            s = b[Row + n - 1][Column + n - 1] - b[Row + n - 1][Column-1] - b[Row-1][Column + n - 1] + b[Row - 1][Column - 1];
        else if(Row>=1)
            s= b[Row + n - 1][Column + n - 1] - b[Row- 1][Column+n- 1];
        else if (Column >= 1)
            s = b[Row + n - 1][Column + n - 1] - b[Row+n - 1][Column- 1];
        else
            s = b[Row + n - 1][Column + n - 1];
    }
    else
    {
        if (Row >= 1 && Column >= 1)
            s = w[Row + n - 1][Column + n - 1] - w[Row + n - 1][Column - 1] - w[Row - 1][Column + n - 1] + w[Row - 1][Column - 1];
        else if (Row >= 1)
            s = w[Row + n - 1][Column + n - 1] - w[Row - 1][Column + n - 1];
        else if (Column >= 1)
            s = w[Row + n - 1][Column + n - 1] - w[Row + n - 1][Column - 1];
        else
            s = w[Row + n - 1][Column + n - 1];
    }
    return s;
}

int main()
{
    int n, m, k, i, j, x, y;
    scanf("%d %d %d", &n, &m, &k);
    char c = getchar();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c = getchar();
            if ((c == 'W' && (i + j) % 2 == 0) || (c=='B' && (i + j) % 2 == 1))
            {
                w[i][j] = 0;
                b[i][j] = 1;
            }
            else
            {
                w[i][j] = 1;
                b[i][j] = 0;
            }
        }
        getchar();
    }
    for (i = 0; i < n; i++)
    {
        for (j =1; j < m; j++)
        {
            w[i][j] += w[i][j - 1];
            b[i][j] += b[i][j - 1];
        }
    }
    for (i = 1; i < n; i++)
    {
        w[i][0] += w[i - 1][0];
        b[i][0] += b[i - 1][0];
        for (j = 1; j < m; j++)
        {
            w[i][j] += w[i-1][j];
            b[i][j] += b[i-1][j];
        }
    }
    long long min = 4000001;
    for (i = 0; i <= n - k; i++)
    {
        for (j = 0; j <= m - k; j++)
        {
            x = sum(i, j, k, 0);
            y = sum(i, j, k, 1);
            if (x >= y)
            {
                if (y < min)
                    min = y;
            }
            else
            {
                if (x < min)
                    min = x;
            }
        }
    }
    printf("%lld", min);
}