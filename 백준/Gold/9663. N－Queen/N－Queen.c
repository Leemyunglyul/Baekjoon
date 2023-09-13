int nq = 0;
int q[16];
int n;

int main()
{
    scanf("%d", &n);
    nqueen(1);
    printf("%d", nq);
}

int queen(int m, int j)
{
    for (int i = 1; i < m; i++)
    {
        if (q[i] - j == m - i || j - q[i] == m - i || q[i]==j)
            return 0;
    }
    return 1;
}

int nqueen(int m)
{
    if (m == n+1) {
        nq++;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (queen(m, i) == 0)
            continue;
        q[m] = i;
        nqueen(m + 1);
    }
}