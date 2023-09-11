int sq[64][64];

void divide(int R, int C, int n)
{
    int i, j, wnum, bnum;
    wnum = 0;
    bnum = 0;
    for (i = R; i < R + n; i++)
    {
        for (j = C; j < C + n; j++)
        {
            if (sq[i][j] == 0)
                wnum++;
            else
                bnum++;
        }
    }
    if (bnum == n * n)
        printf("1");
    else if (wnum == n * n)
        printf("0");
    else
    {
        if (n == 1)
            return 0;
        printf("(");
        divide(R, C, n / 2);
        divide(R, C + n / 2, n / 2);
        divide(R + n / 2 , C, n/2);
        divide(R + n / 2, C + n / 2, n / 2);
        printf(")");
    }
}

int main()
{
    int n, i, j;
    char c;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c = getchar();
            sq[i][j] = c - 48;
        }
        getchar();
    }
    divide(0, 0, n);
}