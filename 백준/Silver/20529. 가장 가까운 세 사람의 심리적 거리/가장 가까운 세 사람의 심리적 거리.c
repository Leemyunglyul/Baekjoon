int distance(char word1[], char word2[], char word3[])
{
	int i, n;
	n = 0;
	for (i = 0; i < 4; i++)
	{
		if (word1[i] != word2[i])
			n++;
		if (word3[i] != word2[i])
			n++;
		if (word3[i] != word1[i])
			n++;
	}
	return n;
}

int max_count(int arr[])
{
	int i;
	for (i = 0; i < 16; i++)
	{
		if (arr[i] >= 3)
			return 3;
	}
	for (i = 0; i < 16; i++)
	{
		if (arr[i] == 2)
			return 2;
	}
	return 1;
}

int main()
{
	int n, i, j, x, min, k, l;
	char word[5];
	int a[16];
	char mbti[16][5];
	strcpy(mbti, "ISTJ");
	strcpy(mbti+1, "ISFJ");
	strcpy(mbti+2, "INFJ");
	strcpy(mbti+3, "INTJ");
	strcpy(mbti+4, "ISTP");
	strcpy(mbti+5, "ISFP");
	strcpy(mbti+6, "INFP");
	strcpy(mbti+7, "INTP");
	strcpy(mbti+8, "ESTP");
	strcpy(mbti+9, "ESFP");
	strcpy(mbti+10, "ENFP");
	strcpy(mbti+11, "ENTP");
	strcpy(mbti+12, "ESTJ");
	strcpy(mbti+13, "ESFJ");
	strcpy(mbti+14, "ENFJ");
	strcpy(mbti+15, "ENTJ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		for (j = 0; j < 16; j++)
			a[j] = 0;
		for (j = 0; j < x; j++)
		{
			scanf("%s", word);
			if (strcmp(word, "ISTJ") == 0)
				a[0]++;
			else if (strcmp(word, "ISFJ") == 0)
				a[1]++;
			else if (strcmp(word, "INFJ") == 0)
				a[2]++;
			else if (strcmp(word, "INTJ") == 0)
				a[3]++;
			else if (strcmp(word, "ISTP") == 0)
				a[4]++;
			else if (strcmp(word, "ISFP") == 0)
				a[5]++;
			else if (strcmp(word, "INFP") == 0)
				a[6]++;
			else if (strcmp(word, "INTP") == 0)
				a[7]++;
			else if (strcmp(word, "ESTP") == 0)
				a[8]++;
			else if (strcmp(word, "ESFP") == 0)
				a[9]++;
			else if (strcmp(word, "ENFP") == 0)
				a[10]++;
			else if (strcmp(word, "ENTP") == 0)
				a[11]++;
			else if (strcmp(word, "ESTJ") == 0)
				a[12]++;
			else if (strcmp(word, "ESFJ") == 0)
				a[13]++;
			else if (strcmp(word, "ENFJ") == 0)
				a[14]++;
			else if (strcmp(word, "ENTJ") == 0)
				a[15]++;
		}
		min = 13;
		if (max_count(a) == 3)
			printf("0\n");
		else
		{
			for (j = 0; j < 16; j++)
			{
				if (a[j] == 0)
					continue;
				if (a[j] == 2)
				{
					for (k = 0; k < 16; k++)
					{
						if (a[k] == 0 || k == j)
							continue;
						else if (distance(mbti[j], mbti[j], mbti[k]) < min)
							min = distance(mbti[j], mbti[j], mbti[k]);
					}
				}
			}
			for (j = 0; j < 16; j++)
			{
				if (a[j] == 0)
					continue;
				for (k = 0; k < 16; k++)
				{
					if (k == j || a[k]==0)
						continue;
					for (l = 0; l < 16; l++)
					{
						if (l == k || l==j || a[l]==0)
							continue;
						else if (distance(mbti[j], mbti[k], mbti[l]) < min)
							min = distance(mbti[j], mbti[k], mbti[l]);
					}
				}
			}
			printf("%d\n", min);
		}
	}
}