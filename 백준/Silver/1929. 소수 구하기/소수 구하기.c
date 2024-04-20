int main()
{
    int x, y, k, i, R;
    scanf("%d %d", &x, &y);
    int* arr = (int*)malloc(sizeof(int) * y+1);
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    for (i = 3; i <= y; i+=2)
        arr[i] = -1;
    for (i = 4; i <= y; i += 2)
        arr[i] = 0;
    for (i = 3; i <= y; i+=2)
    {
        if (arr[i] == 0)
            continue;
        arr[i] = 1;
        k = 2;
        R = i * k;
        while (R <= y)
        {
            arr[R] = 0;
            k++;
            R = i * k;
        }
    }
    for (i = x; i <= y; i++)
    {
        if (arr[i] == 1)
            printf("%d\n", i);
    }
}