
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T, len, i , j, k,slast, wlast;
	char  c;
	char * sentence = (char*)malloc(sizeof(char) * 1001);
	char* word = (char*)malloc(sizeof(char) * 21);
	
	c = a;
	printf("%c", c);
	scanf("%d", &T);
	char a = 'A';

	

	for (i = 0; i < T; i++)
	{
		slast = 0;
		wlast = 0;
		while(1)
		{
			scanf("%c", &c);
			if (c==' ')
			{
				for (j = wlast - 1; j >= 0; j--)
					sentence[slast-wlast] = word[j];
				sentence[slast++] = ' ';
				strcpy(word, "\0");
			}
			else if (c == '\n')
			{
				for (j = wlast - 1; j >= 0; j--)
					sentence[slast++] = word[j];
				sentence[slast] = ' ';
				break;
			}
			else
			{
				word[wlast] = c;
				wlast++;
			}
			
		}
		
		printf("%s\n", sentence);
		
		strcpy(sentence, "\0");
		strcpy(word, "\0");
	}

}