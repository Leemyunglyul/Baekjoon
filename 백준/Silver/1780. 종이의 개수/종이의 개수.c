int sq[2187][2187];

void divide(int R, int C, int n, int* n1, int* n2, int* n3)
{
    int i, j, num1, num2, num3;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    for (i = R; i < R + n; i++)
    {
        for (j = C; j < C + n; j++)
        {
            if (sq[i][j] == -1)
                num1++;
            else if (sq[i][j] == 0)
                num2++;
            else
                num3++;
        }
    }
    if (num1 == n * n)
        *n1 = *n1 + 1;
    else if (num2 == n * n)
        *n2 = *n2 + 1;
    else if(num3==n*n)
        *n3 = *n3 + 1;
    else
    {
        if (n == 1)
            return 0;
        divide(R, C, n / 3, n1, n2 , n3);
        divide(R, C+n/3, n / 3, n1, n2, n3);
        divide(R, C + 2* n / 3, n / 3, n1, n2, n3);
        divide(R + n / 3, C, n / 3, n1, n2, n3);
        divide(R + n / 3, C + n / 3, n / 3, n1, n2, n3);
        divide(R + n / 3, C + 2 * n / 3, n / 3, n1, n2, n3);
        divide(R + 2*n / 3, C, n / 3, n1, n2, n3);
        divide(R + 2*n / 3, C + n / 3, n / 3, n1, n2, n3);
        divide(R + 2*n / 3, C + 2 * n / 3, n / 3, n1, n2, n3);
    }
}

int main()
{
    int n, i, j, n1, n2, n3;
    char c;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &sq[i][j]);
        }
    }
    n1 = 0;
    n2 = 0;
    n3 = 0;
    divide(0, 0, n, &n1, &n2, &n3);
    printf("%d\n%d\n%d", n1, n2, n3);
}