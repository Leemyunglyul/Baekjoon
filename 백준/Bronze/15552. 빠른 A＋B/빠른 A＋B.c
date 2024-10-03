int main()
{
    int num, a, b;
    scanf("%d", &num);
    int* arr;
    arr = (int*)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &a, &b);
        *(arr + i) = a + b;
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d\n", *(arr + i));
    }

    return 0;
}