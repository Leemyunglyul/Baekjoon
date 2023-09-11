int sq[128][128];

void divide(int R, int C, int n, int * w, int *b)
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
        *b = *b + 1;
    else if (wnum == n * n)
        *w = *w + 1;
    else
    {
        if (n == 1)
            return 0;
        divide(R, C, n / 2, w, b);
        divide(R + n / 2 , C, n / 2, w, b);
        divide(R, C+n/2, n / 2, w, b);
        divide(R + n / 2, C + n / 2, n / 2, w, b);
    }

}

int main()
{
    int n, i, j, w, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &sq[i][j]);
        }
    }
    w = 0;
    b = 0;
    divide(0, 0, n, &w, &b);
    printf("%d\n%d", w, b);
    
}